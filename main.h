#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int _putchar(char c);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void executecmd(char **argv);
char *get_file_location(char *command);
int stat(const char *pathname, struct stat *statbuf);

#endif /* MAIN_H */