#include "main.h"

/**
 * tokenize - name of the function
 *
 * @args: parameter 1
 * @cmd: parameter 2
 * Return: void
 *
*/
int tokenize(char **args, char *cmd)
{
    int count_tokens = 0, i = 0;
	char *token = NULL;
	char *cmd_copy = NULL;
    const char *delim = " \n";

	/* Copy cmd to cmd_copy */
    strcpy(cmd_copy, cmd);
    
    /* Split the string (cmd) into an array of words */
    token = strtok(cmd, delim);
    
    /* Determine how many tokens are there */
    while (token != NULL)
    {
        count_tokens++;
        token = strtok(NULL, delim);
    }
    count_tokens++;
		
    /* Allocating space to hold the array of strings (tokens) */
    args = malloc(sizeof(char *) * count_tokens);

    /* Store each token in the args array */
	token = strtok(cmd_copy, delim);

    for (i = 0; token != NULL; i++)
    {
        args[i] = malloc(sizeof(char) * strlen(token));
        strcpy(args[i], token);

        token = strtok(NULL, delim);
    }
    args[i] = NULL;

    return (0);
}