#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_HISTORY 10

char historial[MAX_HISTORY][MAX_LINE];
int indiceHistorial = 0;

void agregarAlHistorial(char* comando) {
    strncpy(historial[indiceHistorial], comando, MAX_LINE - 1);
    historial[indiceHistorial][MAX_LINE - 1] = '\0'; // Asegurar la terminación nula
    indiceHistorial = (indiceHistorial + 1) % MAX_HISTORY; // Circular el historial
}

void imprimirHistorial() {
    printf("Historial de comandos:\n");
    for (int i = 0; i < MAX_HISTORY; ++i) {
        if (historial[i][0] != '\0') {
            printf("%d: %s\n", i + 1, historial[i]);
        }
    }
}

int ejecutarComando(char* comando) {
    pid_t pid = fork();

    if (pid == 0) {
        char *args[MAX_LINE / 2 + 1];
        char *token = strtok(comando, " ");

        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        execvp(args[0], args);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int estado;
        wait(&estado);

        if (WEXITSTATUS(estado) == EXIT_SUCCESS) {
            return 0; // Éxito
        } else {
            return -1; // El comando falló
        }
    } else {
        return -1; // Error al crear el proceso hijo
    }
}

int main() {
    char comando[MAX_LINE];

    while (1) {
        printf("Ingrese un comando ('historial' para ver el historial): ");
        fgets(comando, MAX_LINE, stdin);
        comando[strcspn(comando, "\n")] = '\0'; // Elimina el carácter de nueva línea agregado por fgets

        if (strcmp(comando, "historial") == 0) {
            imprimirHistorial();
        } else {
            int resultado = ejecutarComando(comando);

            if (resultado == 0) {
                printf("Comando ingresado: Pasado - '%s' se ejecutó correctamente.\n", comando);
                agregarAlHistorial(comando);
            } else {
                printf("Comando ingresado: Fallido - Error al ejecutar '%s'.\n", comando);
            }
        }
    }

    return 0;
}
