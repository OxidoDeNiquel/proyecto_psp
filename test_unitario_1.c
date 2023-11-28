#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

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
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        return -1; // Error al crear el proceso hijo
    }

    return 0; // Éxito
}

int main() {
    char comando[100];
    printf("Introduce un comando válido: ");
    scanf("%s", comando);

    int resultado = ejecutarComando(comando);

    if (resultado == 0) {
        printf("Prueba 1: Pasada - El comando '%s' se ejecutó correctamente.\n", comando);
    } else {
        printf("Prueba 1: Fallida - Error al ejecutar el comando '%s'.\n", comando);
    }

    return 0;
}

