#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char *command;                  // Variable to store the user command
    char buffer[BUFFER_SIZE];       // Buffer to read user input
    ssize_t read_bytes;             // Number of bytes read from user input

    while (1)
    {
        printf("#cisfun$ ");        // Display prompt

        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);   // Read user input from stdin
        if (read_bytes == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        else if (read_bytes == 0)
        {
            printf("\n");           // Print newline and break the loop on "end of file" condition (Ctrl+D)
            break;
        }

        buffer[read_bytes - 1] = '\0';  // Remove newline character from user input

        command = strtok(buffer, " "); // Tokenize user input to get the command

        if (command != NULL)
        {
            pid_t pid = fork();        // Fork a child process

            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                // Child process
                if (execvp(command, &command) == -1)   // Execute the command using execvp
                {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                // Parent process
                wait(NULL);             // Wait for the child process to complete
            }
        }
    }

    return 0;
}
