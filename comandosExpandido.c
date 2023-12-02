#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#define MAX_LINE 80 /* Longitud máxima del comando */

int main() {
    char input[MAX_LINE];
    int should_run = 1;
    int eleccion = 0; // Variable para elegir entre execvp y system

    while (should_run) {
        printf("MiShell> ");
        fflush(stdout);

        struct timeval start_time, end_time;

        // Captura el tiempo de inicio antes de recibir la entrada
        gettimeofday(&start_time, NULL);

        fgets(input, MAX_LINE, stdin);
        input[strlen(input) - 1] = '\0'; // Reemplazar el salto de línea

        if (strcmp(input, "exit") == 0) {
            should_run = 0;
        } else {
            printf("Elija método (1 para execvp, 2 para system): ");
            int method;
            scanf("%d", &method);
            getchar(); // Limpiar el buffer del salto de línea

            switch (method) {
                case 1:
                    eleccion = 0;
                    break;
                case 2:
                    eleccion = 1;
                    break;
                default:
                    printf("Método no válido. Se usará execvp por defecto.\n");
                    eleccion = 0;
                    break;
            }

            pid_t pid = fork();

            if (pid == 0) {
                // Proceso hijo
                char *args[MAX_LINE / 2 + 1];
                char *token = strtok(input, " ");

                int i = 0;
                while (token != NULL) {
                    args[i] = token;
                    token = strtok(NULL, " ");
                    i++;
                }
                args[i] = NULL;

                if (eleccion) {
                    system(input);
                    exit(0);
                } else {
                    execvp(args[0], args);
                    perror("Error en execvp"); // Mostrar un mensaje de error si execvp falla
                    exit(EXIT_FAILURE);
                }
            } else {
                wait(NULL); // Proceso padre esperando al hijo

                // aqui pillamos el tiempo en el que se termina el método
                gettimeofday(&end_time, NULL);

                // Calcula el tiempo de ejecución en milisegundos
                long execution_time = (end_time.tv_sec - start_time.tv_sec) * 1000 +
                                      (end_time.tv_usec - start_time.tv_usec) / 1000;

                printf("Comando ejecutado en %ld milisegundos.\n", execution_time);
            }
        }
    }

    return 0;
}
