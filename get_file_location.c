#include "main.h"

char *get_file_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int cmd_length, dir_len;
    struct stat buffer;

    /* get the value of the file path */
    path = getenv("PATH");

    if (path){
        /* make a copy of the file path */
        path_copy = strdup(path);

        /* get length of the command */
        cmd_length = strlen(command);

        /* break down path_copy variable into individual tokens */
        path_token = strtok(path_copy, ":");

        while (path_token != NULL)
        {
            dir_len = strlen(path_token);

            file_path = malloc(cmd_length + dir_len + 2);

            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0)
            {
                /* return value of 0 means success implying that the file_path is valid*/
                /* free up allocated memory before returning your file_path */

                free(path_copy);

                return (file_path);
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        } 

        /* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */
        free(path_copy);

        if (stat(command, &buffer) == 0)
        {
            return (command);
        }
        
        return (NULL);
    }

    return (NULL);
}