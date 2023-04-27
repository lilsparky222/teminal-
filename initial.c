#include "main.h"

/**
 * main - entry point for the shell program
 *
 * @ac: count of arguments
 * @argv: pointer to the array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **argv)
{
    char *cmd = NULL, *cmd_copy = NULL, *token;
    size_t n = 0;
    ssize_t read_chars;
    const char *delim = " \n";
    int number_tokens = 0, i = 0;

    /* Declare unused variables */
    (void)ac;

    /* Create an infinite loop */
    while (1)
    {
        /* Print a prompt for the user to make an entry */
        printf("$hell -$ ");

        /* Get the user entry */
        read_chars = getline(&cmd, &n, stdin);

        /* Check if the getline function failed or reached EOF or user use CTRL + D */
        if (read_chars == -1)
        {
            printf("Exiting shell...\n");
            break;
        }

        /* Allocate space for a copy of the cmd */
        cmd_copy = malloc(sizeof(char) * read_chars);
        if (cmd_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }

        /* Copy cmd to cmd_copy */
        strcpy(cmd_copy, cmd);

        /* Split the string (cmd) into an array of words */
        token = strtok(cmd, delim);

        /* Determine how many tokens are there */
        while (token != NULL)
        {
            number_tokens++;
            token = strtok(NULL, delim);
        }
        number_tokens++;

        /* Allocating space to hold the array of strings (tokens) */
        argv = malloc(sizeof(char *) * number_tokens);

        /* Store each token in the argv array */
        token = strtok(cmd_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* Execute the command */
        executecmd(argv);
    }

    /* Free up allocated memory */
    free(cmd);
    free(cmd_copy);

    return (0);
}
