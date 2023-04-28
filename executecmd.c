<<<<<<< HEAD
#include "main.h"

void executecmd(char **argv)
{
    char *command = NULL, *usr_command = NULL;

    if (argv)
    {
        /* get the command */
        command = argv[0];

        /* generate path to the command before passing it to the execve */
        usr_command = get_file_location(command);

        /* execute the user command the execve */
        if (execve(usr_command, argv, NULL) == -1)
        {
            perror("Error:");
        }
    }
    
}
=======
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
>>>>>>> af246cffb84fd34a28b8263c5a9f3058ef89330f
