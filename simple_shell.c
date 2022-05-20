#include "shell.h"

/**
 * main - start of program execution
 * @ac: main argc, count of arguments to main
 * @av: string array of arguments to main
 *
 * Return: 0(Sucess)
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line;
	int i;
	args_t vectors = {NULL, NULL, NULL, 1};
	int pipe = 0;

	vectors.env = _env(environ);
	vectors.av = av;

	if (isatty(STDIN_FILENO) == 1)
		pipe = 1;
	while (1)
	{
		if (pipe == 1)
			_printf("$ ");
		line = _getline();
		if (line[0] == '\0' || line[1] == '\0' || _strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		vectors.argv = tokenize(line, " \n\t\r");
		if (vectors.argv[0] == NULL)
			continue;
		if (strcmp(vectors.argv[0], "env") == 0)
		{
			for (i = 0; environ[i]; i++)
			{
				_printf(environ[i]);
				_printf("\n");
			}
		}
		else if (_strcmp(vectors.argv[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		if (vectors.argv && vectors.argv[0])
			path_validate(&vectors);
		free(line);
		free(vectors.argv);
	}
	free(vectors.env);
	return (0);
}
