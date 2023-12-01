#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* Longitud máxima del comando */
#define MAX_NAME 50

void progressBar(int progress, int total);

int main() {
    char input[MAX_LINE];
    int should_run = 1;
    char nombreShell[MAX_NAME] = "MiShell";

    while (should_run) {
        printf("%s> ", nombreShell);
        fflush(stdout);

        fgets(input, MAX_LINE, stdin);

        // Reemplazar el salto de línea con un terminador de cadena
        input[strlen(input) - 1] = '\0';

        // Salir si el usuario ingresa "exit"
        if (strcmp(input, "opextra") == 0) {
            printf("Opciones adicionales: \n");
            printf("exit \n");
            printf("changeNameShell \n");
            printf("comandoOculto\n");

        } else if(strcmp(input, "exit") == 0){
            should_run = 0;

        } else if(strcmp(input, "changeNameShell") == 0){
            printf("Introduce un nombre para la shell: ");
            fgets(nombreShell, MAX_NAME, stdin);
            nombreShell[strlen(nombreShell) - 1] = '\0'; 

            printf("Nombre de la shell cambiado a %s\n", nombreShell);

        } else if(strcmp(input, "comandoOculto") == 0){
            const int totalSteps = 100;

            for (int i = 0; i <= totalSteps; i++) {
                progressBar(i, totalSteps);
                usleep(100000); // Simula alguna tarea que lleva tiempo
            }

            printf(" _______  _______  _______  _______  _______      _______  _______  _______           _______  ______   _______  _        _______  _______     _  ______  \n");
            printf("(  ___  )(  ____ \\(  ____ \\(  ___  )(  ____ )    (  ___  )(  ____ )(  ____ )|\\     /|(  ____ )(  ___ \\ (  ___  )( (    /|(  ___  )(  ____ \\   / )/ ___  \\ \n");
            printf("| (   ) || (    \\/| (    \\/| (   ) || (    )|    | (   ) || (    )|| (    )|| )   ( || (    \\/| (   ) )| (   ) ||  \\  ( || (   ) || (    \\/  / / \\/   \\  \\ \n");
            printf("| |   | || (_____ | |      | (___) || (____)|    | (___) || (____)|| (____)|| |   | || (__    | (__/ / | (___) ||   \\ | || |   | || (_____  / /     ___) / \n");
            printf("| |   | |(_____  )| |      |  ___  ||     __)    |  ___  ||  _____)|     __)| |   | ||  __)   |  __ (  |  ___  || (\\ \\) || |   | |(_____  )( (     (___ ( \n");
            printf("| |   | |      ) || |      | (   ) || (\\ (       | (   ) || (      | (\\ (   | |   | || (      | (  \\ \\ | (   ) || | \\   || |   | |      ) | \\ \\        ) \\ \n");
            printf("| (___) |/\\____) || (____/\\| )   ( || ) \\ \\__    | )   ( || )      | ) \\ \\__| (___) || (____/| )___) )| )   ( || )  \\  || (___) |/\\____) |  \\ \\ /\\___/  / \n");
            printf("(_______)\\_______)(_______/|/     \\||/   \\__/    |/     \\||/       |/   \\__/(_______)(_______/|/ \\___/ |/     \\||/    )_)(_______)\\_______)   \\_)\\______/  \n");

            printf("⠀⠀⢀⣠⠤⠶⠖⠒⠒⠶⠦⠤⣄⠀⠀⠀⣀⡤⠤⠤⠤⠤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⣴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣦⠞⠁⠀⠀⠀⠀⠀⠀⠉⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⡾⠁⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣘⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⢀⡴⠚⠉⠁⠀⠀⠀⠀⠈⠉⠙⠲⣄⣤⠤⠶⠒⠒⠲⠦⢤⣜⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⡄⠀⠀⠀⠀⠀⠀⠀⠉⠳⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠹⣆⠀⠀⠀⠀⠀⠀⣀⣀⣀⣹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⣠⠞⣉⣡⠤⠴⠿⠗⠳⠶⣬⣙⠓⢦⡈⠙⢿⡀⠀⠀⢀⣼⣿⣿⣿⣿⣿⡿⣷⣤⡀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⣾⣡⠞⣁⣀⣀⣀⣠⣤⣤⣤⣄⣭⣷⣦⣽⣦⡀⢻⡄⠰⢟⣥⣾⣿⣏⣉⡙⠓⢦⣻⠃⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠉⠉⠙⠻⢤⣄⣼⣿⣽⣿⠟⠻⣿⠄⠀⠀⢻⡝⢿⡇⣠⣿⣿⣻⣿⠿⣿⡉⠓⠮⣿⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠙⢦⡈⠛⠿⣾⣿⣶⣾⡿⠀⠀⠀⢀⣳⣘⢻⣇⣿⣿⣽⣿⣶⣾⠃⣀⡴⣿⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠙⠲⠤⢄⣈⣉⣙⣓⣒⣒⣚⣉⣥⠟⠀⢯⣉⡉⠉⠉⠛⢉⣉⣡⡾⠁⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⣠⣤⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⡿⠋⠀⠀⠀⠀⠈⠻⣍⠉⠀⠺⠿⠋⠙⣦⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⣀⣥⣤⠴⠆⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⠖⠋⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀⠀⠀⠀\n");
            printf("⠸⢫⡟⠙⣛⠲⠤⣄⣀⣀⠀⠈⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠏⣨⠇⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠻⢦⣈⠓⠶⠤⣄⣉⠉⠉⠛⠒⠲⠦⠤⠤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣠⠴⢋⡴⠋⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠉⠓⠦⣄⡀⠈⠙⠓⠒⠶⠶⠶⠶⠤⣤⣀⣀⣀⣀⣀⣉⣉⣉⣉⣉⣀⣠⠴⠋⣿⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠛⠒⠒⠒⠒⠒⠤⠤⠤⠒⠒⠒⠒⠒⠒⠚⢉⡇⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠚⠛⠳⣤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠋⠙⢷⡋⢙⡇⢀⡴⢒⡿⢶⣄⡴⠀⠙⠳⣄⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⢷⡄⠀⠀⠘⣶⢋⡞⠁⠀⠀⢀⡴⠂⠀⠀⠀⠀⠈⢧⡀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠞⣲⠄⠈⠛⢻⠛⢉⡴⣋⡴⠟⠁⠀⠀⠀⠀⠈⢷⡄⠙⣆⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠏⣠⠞⣗⠲⠤⣄⣀⠀⠀⠀⠀⠀⠀⠈⠳⠀⠀⠀⠀⠀⢸⣧⠇⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣾⣅⠓⠶⠤⣄⣉⠉⠉⠛⠒⠲⠦⠤⠤⠤⠒⠒⠚⠲⣄⠡⠏⠀⠀\n");
            

        } else {
            pid_t pid = fork();

            if (pid == 0) {
                // Este es el proceso hijo
                char *args[MAX_LINE / 2 + 1]; // Argumentos del comando
                char *token = strtok(input, " ");

                int i = 0;
                while (token != NULL) {
                    args[i] = token;
                    token = strtok(NULL, " ");
                    i++;
                }
                args[i] = NULL; // Marcar el final de los argumentos

                // Manejo de errores en execvp
                if (execvp(args[0], args) == -1) {
                    perror("Error al ejecutar el comando");
                    exit(EXIT_FAILURE);
                }

            } else {
                // Este es el proceso padre
                wait(NULL);
            }
        }
    }

    return 0;
}

void progressBar(int progress, int total) {
    const int barLength = 50;
    int progressLength = (int)((double)progress / total * barLength);

    printf("[");
    for (int i = 0; i < barLength; i++) {
        if (i < progressLength) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %3d%%\r", (int)((double)progress / total * 100));
    fflush(stdout);
}