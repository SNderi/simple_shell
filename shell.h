#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * struct arguments - structure that holds the arg vector from stdin and an
 * environment variable
 * @argv: string array of the command arguments
 * @env: string array of env values
 * @av: argument to main
 * @count: to be used in p_error
 */
typedef struct arguments
{
	char **argv;
	char **env;
	char **av;
	unsigned int count;
} args_t;

extern char **environ;

char *_getline();
char **tokenize(char *line, char *del);
char **_realloc(char **ptr, size_t *size);

void _printf(char *string);
void p_error(args_t *vec, char *message);
void p_error(args_t *vec, char *message);
char *_uitoa(unsigned int num);

void _strcpy(char *dest, char *src);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

int path_check(char *arg);
char *find_path(char **envp);
int exec_current(args_t *vec);
int exec_path(char *commandpath, args_t *vec);
void path_validate(args_t *vec);

char **_env(char **env);
void env_f(char **env);



#endif /* SHELL_H */
