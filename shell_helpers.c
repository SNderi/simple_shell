#include "shell.h"

/**
 *_getline - gets arguments from stdin and stores them in the string array line
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
			perror("readline");
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
	int i = 0;
	int size = 64;
	char *token;
	char **av = malloc(sizeof(char *) * size); /* max of 64 pointers */
	char *delimiter = " \n";

	token = strtok(line, delimiter);
	while (token != NULL)
	{
		av[i] = token;
		i++;
		
		if (i >= size)
		{
			size += size;
			av = realloc(av, size * sizeof(char *));
			if (av == NULL)
			{
				printf("Error on realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimiter);
	}
	av[i] == NULL;
	/* check if av contains the required commands
	i = 0;
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	printf("%d\n", size);
	*/

	token = NULL;
	free(token);
	return (av);
}

/**
 * _exec - runs the exec function on different arguments
 * @args: input string array of arguments
 *
 * Return: int
 */
int _exec(char **args)
{
	pid_t pid;
	int a;
	extern char **environ;

	pid = fork();
	if (pid == 0) /* child process */
	{
		if ((execve(args[0], args, environ)) == -1)
			printf("%s: %s\n", args[0], strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		printf("%s: %s\n", args[0], strerror(errno));
	else /* parent process */
	{
		wait(NULL);
	}
	return (1);
}
