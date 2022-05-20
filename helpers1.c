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
	size_t len = 0;

	/* getline takes the line from stdin and puts it in a buffer */
	count = getline(&line, &len, stdin);
	if (count == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("Error: getline()");
			return (NULL);
		}
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
	size_t position = 0;
	int len, x;
	char *token, *new;
	size_t i = 64;
	char **tokens = malloc(i* sizeof(char *));

	if (tokens == NULL)
	{
		perror("Error: malloc() in tokenize()");
		exit(EXIT_FAILURE);
	}

	len = _strlen(line); /* new is equal line */
	new = malloc(len);
	_strcpy(new, line);

	token = strtok(new, del);
	while (token != NULL)
	{
		x = _strlen(token);
		tokens[position] = malloc(x * sizeof(char));
		_strcpy(tokens[position], token);
		position++;

		if (position >= i)
		{
			i += 64;
			tokens = _realloc(tokens, &i);
			if (tokens == NULL)
			{
				perror("Error: realloc() in tokenize()");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, del);
	}
	tokens[position] = NULL;
	free(new);
	return (tokens);
}
