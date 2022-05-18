#include "shell.h"

/**
 * _getline - gets line from stdin and stores in the string array line
 *
 * Return: the newly created string of arguments, line
 */
char *_getline()
{
	int count;
	char *line = NULL;
	ssize_t len = 0;

	/* getline takes the line from stdin and puts it in a buffer */
	count = getline(&line, &len, stdin);
	if (count == -1)
	{
		fprintf(stdout, "%s", strerror(errno));
	}

	return (line);
}

/**
 * tokenize - tokenizes a string with a delimiter
 * @line: input buffer
 * @del: delimiter to use
 *
 * Return: pointer to an array of strings
 */
char **tokenize(char *line, char *del)
{
	size_t size = 10;
	int i = 0;
	char **av = NULL;
	char *token;

	if (line == NULL)
		return (NULL);

	av = malloc(size * sizeof(char *));
	if (av == NULL)
	{
		perror("error on malloc allocation");
		return (NULL);
	}

	while ((av[i] = strtok(line, del)) != NULL)
	{
		i++;
		if (i == size)
		{
			av = realloc(av, size);
			if (av == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		line = NULL;
	}
	return (av);
}

/**
 * _exec - runs the exec function on different arguments
 * @args: input string array of arguments
 * @env: input string array of environment variables
 *
 * Return: int
 */
int _exec(char **args, char **env)
{
	pid_t pid;

	if (!args[0])
		return (1);

	pid = fork();
	if (pid == 0) /* child process */
	{
		if ((execve(args[0], args, env)) == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("fork");
	else /* parent process */
		wait(NULL);
	return (1);
}