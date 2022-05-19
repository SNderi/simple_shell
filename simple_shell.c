#include "shell.h"

/**
 * main - start of program execution
 * @ac: number of strings in av
 * @av: array of commands to pass to exec
 * @env: array of environment variables
 *
 * Return: 0(Sucess)
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	int status, i;
	args_t vectors = {NULL, NULL};

	vectors.env = _env(env);
	while (1)
	{
		printf("$ ");
		line = _getline();
		if (line[0] == '\0' || _strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		vectors.argv = tokenize(line, " \n");

		/* checks if we have the argv vector */
		for (i = 0; vectors.argv[i] != NULL; i++)
		{
			_printf(vectors.argv[i]);
			_printf(" Tokenize works well");
		}
		_printf("\n");

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
			exit(status);
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
