#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command, char *args[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(command, args);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        // Error forking
        perror("fork");
    }
}

int parse_arguments(char *command, char *args[]) {
    int count = 0;

    // Tokenize command by space
    char *token = strtok(command, " \t\n");

    while (token != NULL && count < MAX_ARGUMENTS) {
        args[count] = token;
        count++;
        token = strtok(NULL, " \t\n");
    }

    args[count] = NULL;  // Set the last argument to NULL

    return count;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];

    while (1) {
        printf("$ ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

        if (strlen(input) == 0) {
            continue;  // Skip empty commands
        }

        int num_args = parse_arguments(input, args);
        execute_command(args[0], args);
    }

    return 0;
}
