#include "shell.h"

/**
 * main - start of program execution
 * @ac: number of strings in av
 * @av: array of commands to pass to exec
 *
 * Return: 0(Sucess)
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args;
	extern char **environ;
	int status, i;

	while (1)
	{
		printf("$ ");
		line = _getline();
		args = tokenize(line);
		if (strcmp(args[0], "env") == 0)
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
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
