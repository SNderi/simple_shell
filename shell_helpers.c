#include "shell.h"

/**
 * _getline - gets arguments from stdin and stores them in the string array line
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
		if(feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	//printf("%s", line);
	return (line);
}

/**
 * tokenize - tokenizes each work in the line from _getline
 * @line: input line
 *
 * Return: pointer to an array of strings
 */
char **tokenize(char *line)
{
	int size = 64, i = 0;
	char **av = malloc(size * sizeof(char *));
	char *token;

	if (av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n");
	while (token != NULL)
	{
		av[i] = token;
		i++;

		if (i >= size)
		{
			size += size;
			av = realloc(av, size * sizeof(char*));
			if (!av)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \n");
	}
	av[i] = NULL;
	return (av);
}
/**
 * _exec - runs the exec function on different arguments
 * @args: input string array of arguments
 *
 * Return: int
 */
int _exec(char **args, char **env)
{
	pid_t pid;

	if (args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == 0) /* child process */
	{
		if ((execve(args[0], args, env)) == -1);
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	        perror("fork");
	else /* parent process */
	{
		wait(NULL);
	}
	return (1);
}
