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
char **tokenize(char *line, char*del)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(64 * sizeof(char *));
	char *token, *new;
	int len;

	if (!tokens) {
		perror("Error: malloc() in tokenize()");
		exit(EXIT_FAILURE);
	}

	len = strlen(line);
	new = malloc(len);
	strcpy(new, line);

	token = strtok(new, " ");
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				perror("Error: realloc() in tokenize()");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	free(new);
	return tokens;
}
