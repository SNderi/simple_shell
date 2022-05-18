#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.>
#include <errno.h>

typedef struct arguments
{
	char **argv;
	char **env;
}args_t;

char *_getline();
char **tokenize(char *line, char *del);
int _exec(char **args, char **env);
void _printf(char *string);
void _strcpy(char *dest, char *src);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_getenv(char *name);

#endif /* SHELL_H */
