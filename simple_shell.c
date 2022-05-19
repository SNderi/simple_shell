#include "shell.h"

/**
 * main - start of program execution
 *
 *
 * Return: 0(Sucess)
 */
int main(void)
{
	char *line;
	int i;
	args_t vectors = {NULL, NULL};

	vectors.env = _env(environ);
	while (1)
	{
		printf("$ ");
		line = _getline();
		if (line[0] == '\0' || line[1] == '\0' || _strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		vectors.argv = tokenize(line, " \n");

		if (strcmp(vectors.argv[0], "env") == 0)
		{
			for (i = 0; environ[i]; i++)
			{
				_printf(environ[i]);
				_printf("\n");
			}
		}
		else if (strcmp(vectors.argv[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		if (vectors.argv && vectors.argv[0])
		{
			path_validate(&vectors);
		}

		free(line);
		free(vectors.argv);
	}
	free(vectors.env);
	return (0);
}
