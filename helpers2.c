#include "shell.h"

/**
 * _printf - prints a string to stdout
 * @string: input string that is null terminated
 *
 * Return: void
 */
void _printf(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		write(1, &string[i], 1);
}
