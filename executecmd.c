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