#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char *_getline();
char **tokenize(char *line);
int _exec(char **args, char **env);

#endif /* SHELL_H */
