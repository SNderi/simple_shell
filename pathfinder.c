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

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * find_path - Finds PATH variable
 * @env: Environment variables arrray
 *
 * Return: Pointer to node that contains the PATH, NULL on failure
 */

char *find_path(char **env)
{
	char *path = "PATH=";
	int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}

/**
 * exec_current - executes the command in the current working directory
 * @vec: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int exec_current(args_t *vec)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(vec->argv[0], &buf) == 0)
	{
		if (access(vec->argv[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				perror("Error: fork() in exec_current");
			if (child_pid == 0)
			{
				if (execve(vec->argv[0], vec->argv, vec->env) == -1)
					perror("Error: Exec() in exec_current()");
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
			perror("Error: access() in exec_current()");
		}
			return (0);
	}
	p_error(vec, "not found");
	return (0);
}


/**
 * exec_path - executes commands with a full path
 * @command_path: full path to the command
 * @vec: pointer to struct of string array
 *
 * Return: 0 on succcess, 1 on failure
 */
int exec_path(char *command_path, args_t *vec)
{
	pid_t child_pid;

	if (access(command_path, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Error: forking in exec_path");
		if (child_pid == 0)
		{
			if (execve(command_path, vec->argv, vec->env) == -1)
				perror("Error: execve in exec_path");
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
		perror("Error: Access in exec_path");
	}
	return (0);
}


/**
 * path_validate - Checks if command is a path and executes else finds it in
 * path variable and executes it
 * @vec: Argument vector
 *
 * Return: void
 */

void path_validate(args_t *vec)
{
	int result = 0;
	char *path;
	char *path_duplicate = NULL, *check = NULL;
	unsigned int i = 0;
	char **tokens;
	struct stat buf;

	if (path_check(vec->argv[0])) /* if command is a full path */
		result = exec_current(vec);
	else
	{
		path = find_path(vec->env); /* Returns PATH string */

		if (path != NULL)
		{
			path_duplicate = _strdup(path + 5); /* removing PATH= */
			tokens = tokenize(path_duplicate, ":");
			for (i = 0; tokens && tokens[i]; i++)
			{
				check = _strcat(tokens[i], vec->argv[0]);

				if (stat(check, &buf) == 0)
				{
					result = exec_path(check, vec);
					free(check);
					break;
				}
			}
			free(path_duplicate);
			if (tokens == NULL)
				exit(EXIT_FAILURE);
		}
		if (path == NULL || tokens[i] == NULL)
		{
			p_error(vec, "not found");
		}
		free(tokens);
	}
	if (result == 1)
		exit(EXIT_SUCCESS);
}
