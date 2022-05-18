#include "shell.h"

/**
 * path_check - Checks if a command is a part of a path
 * @arg: Command to check
 * 
 * Return: 1 - success, 0- failure
 */

int path_check(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * find_path - Finds PATH variable
 * @envp: Environment variables arrray
 *
 * Return: Pointer to node that contains the PATH, NULL on failure
 */

char *find_path(char **envp)
{
	char *path = "PATH=";
	int i, j;

	for (i = 0; envp[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != envp[i][j])
				break;
		if (j == 5)
			break;
	}
	return (envp[i]);
}

/**
 * path_validate - Checks if command is in PATH
 * @args: Argument vector
 *
 * Return: void
 */

void path_validate(char **args)
{
	if (path_check(ars[0]))
			_exec(args[0
}
