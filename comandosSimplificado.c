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

    while (should_run) {
        printf("MiShell> ");
        fflush(stdout);

        fgets(input, MAX_LINE, stdin);

        // Reemplazar el salto de línea con un terminador de cadena
        input[strlen(input) - 1] = '\0';

        // Salir si el usuario ingresa "exit"
        if (strcmp(input, "exit") == 0) {
            should_run = 0;
        } else {
            system(input);
        }
    }

    return 0;
}
