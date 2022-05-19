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

typedef struct arguments
{
	char **argv;
	char **env;
}args_t;

extern char **environ;

char *_getline();
char **tokenize(char *line, char *del);

void _printf(char *string);

void _strcpy(char *dest, char *src);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);

int path_check(char *arg);
char *find_path(char **envp);
int exec_current(args_t *vec);
int exec_path(char *commandpath, args_t *vec);
void path_validate(args_t *vec);

char **_env(char **env);
void env_f(char **env);



#endif /* SHELL_H */
