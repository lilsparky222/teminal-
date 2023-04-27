#include "main.h"

/**
 * executecmd - get the command, generate path to the command before passing
 * it to the execve, and execute the command with execve
 *
 * @argv: pointer to the array of arguments
 *
 * Return: void
 */
void executecmd(char **argv)
{
	char *command = NULL, *usr_command = NULL;

	if (argv)
	{
		command = argv[0];
		usr_command = get_file_location(command);
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
