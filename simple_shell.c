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
	char **args;
	int status, i;
	char *delimiter = " \n";

	while (1)
	{
		printf("$ ");
		if (STDIN_FILENO == '\n')
		{
			_printf("this is it!");
			continue;
		}
		line = _getline();
		args = tokenize(line, delimiter);
		if (strcmp(args[0], "env") == 0)
		{
			for (i = 0; environ[i]; i++)
			{
				_printf(environ[i]);
				_printf("\n");
			}
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			exit(status);
		}
		else
			_exec(args, env);

		free(line);
		free(args);
	}

	return (0);
}
