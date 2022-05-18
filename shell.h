#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


char *_getline();
char **tokenize(char *line);
int _exec(char **args, char **env);
int shell_exit();
int print_env();

#endif /* SHELL_H */
