#include "main.h"

/**
 * main - name of the function
 *
 * @ac: parameter 1
 * @argv: parameter 2
 * @: parameter 3
 * Return: 0
 *
*/
int main(int ac, char *argv[])
{
	char *cmd = NULL, *cmd_copy = NULL, **args = NULL;
	size_t n = 0;
	ssize_t read_chars;

	/* Declaring void variables */
	(void)ac;
	
	/* Create an infinite loop */
	while (1)
	{
		/* print a prompt for the user to make an entry */
		printf("$hell -$ ");
		
		/* get the user entry */
		read_chars = getline(&cmd, &n, stdin);
		
		/* Check if the getline function failed or reached EOF or user use CTRL + D */
		if (read_chars == -1)
		{
			printf("Exiting shell...\n");
		}
		
		/* Allocate space for a copy of the cmd */
		cmd_copy = malloc(sizeof(char) * read_chars);
		
		if (cmd_copy == NULL)
		{
			perror("tsh: memory allocation error");
			
			return (-1);
		}
		
        tokenize(args, cmd);
		
        /* Execute the command */
        executecmd(argv);


    }

    /* Free up allocated memory */
    free(cmd);
    free(cmd_copy);

    return (0);
}
