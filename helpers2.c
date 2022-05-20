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


/**
 * p_error - prints error to std error
 * @vec: pointer to struct of variables
 * @message: message to print
 *
 * Return: void
 */
void p_error(args_t *vec, char *message)
{
	char *count;

	_printf(vec->av[0]);
	_printf(": ");
	count = _uitoa(vec->count);
	_printf(count);
	free(count);
	_printf(": ");
	_printf(vec->argv[0]);
	_printf(": ");
	if (message)
	{
		_printf(message);
		_printf("\n");
	}
	else
		perror("");
}

/**
 * _uitoa - converts  unsigned int to a string
 * @num: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int num)
{
	char *str;
	unsigned int hodl, digits;

	hodl = num;
	for (digits = 0; hodl != 0; digits++)
		hodl /= 10;
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	str[digits] = '\0';
	for (--digits; num; --digits)
	{
		str[digits] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
