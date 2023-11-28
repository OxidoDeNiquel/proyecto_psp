#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* Longitud máxima del comando */

int main() {
    char input[MAX_LINE];
    int should_run = 1;
    int eleccion = 0; // Variable para elegir entre execvp y system

    while (should_run) {
        printf("MiShell> ");
        fflush(stdout);

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
                } else {
                    execvp(args[0], args);
                    exit(0);
                }
            } else {
                wait(NULL); // Proceso padre esperando al hijo
            }
        }
    }

    return 0;
}