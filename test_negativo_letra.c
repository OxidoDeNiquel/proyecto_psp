#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LINE 80

int esLetra(char c) {
    return isalpha(c);
}

int ejecutarComando(char* comando) {
    // Verificar si el primer carácter del comando es una letra
    if (!esLetra(comando[0])) {
        printf("Error: El comando no comienza con una letra.\n");
        return -1;
    }

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
    char comando_inexistente[] = "xyzabc";
    int resultado = ejecutarComando(comando_inexistente);

    if (resultado == -1) {
        printf("Prueba 2: Fallida - Error al ejecutar comando inexistente.\n");
    } else {
        printf("Prueba 2: Pasada - El comando inexistente se ejecutó correctamente.\n");
    }

    return 0;
}
