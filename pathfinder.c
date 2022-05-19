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

void path_validate(args_t vec)
{
	int result = 0;
	char *path;
	char *duplicate = NULL;
	char *check = NULL;
	unsigned int i = 0;
	char **tokens;
	struct stat buf;

	if (path_check(vec.argv[0]))
		_exec(vec.argv, vec.env);
	else
	{
		path = find_path(vec.env);
		if (path != NULL)
		{
			duplicate = strdup(path + 5);
			tokens = tokenize(duplicate, ":");
			for (i = 0; tokens && tokens[i]; i++)
			{
				check = _strcat(tokens[i], vec.argv[0]);
				if (stat(check, &buf) == 0)
				{
					result = exec_path(check, vec);
					free(check);
					break;
				}
				free(check);
			}
			free(duplicate);
			if (tokens == NULL)
			{
				exit;
			}
		}
		if (path == NULL || tokens[i] == NULL)
		{
		        perror(vec.argv[0]);
		}
		free(tokens);
	}
	if (result == 1)
		exit;
}

/**
 * exec_path - executes commands in the path
 * @path: full path to the command
 * @vars: pointer to struct of variables
 *
 * Return: 0 on succcess, 1 on failure
 */
int exec_path(char *path, args_t vec)
{
	pid_t child_pid;

	if (access(path, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror(vec.argv[0]);
		if (child_pid == 0)
		{
			if (execve(path, vec.argv, vec.env) == -1)
				perror(vec.argv[0]);
		}
		else
		{
			wait(NULL);
			return (0);
		}
		return (1);
	}
	else
	{
		perror(vec.argv[0]);
	}
	return (0);
}
