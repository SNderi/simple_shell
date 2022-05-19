#include "shell.h"

/**
 * _env - parse in env from main
 * @env: env from main
 *
 * Return: pointer to the new environment
 */
char **_env(char **env)
{
	char **new_env = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
	{
		perror("Error: malloc in _env");
		return (NULL);;
	}
	for (i = 0; env[i] != NULL; i++)
		new_env[i] = strdup(env[i]);
	new_env[i] = NULL;

	return (new_env);
}

/**
 * env_f - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void env_f(char **env)
{
	unsigned int i;

	/* frees many pointers in an array of strings */
	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
