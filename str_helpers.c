#include "shell.h"

/**
 * _strcpy - copies a string to another buffer
 * @dest: file to copy to
 * @src: file to copy from
 *
 * Return: void
 */
void _strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * _strlen - returns the length of a string
 * @string: input string
 *
 * Return: number of characters in a string
 */
int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcmp - compares to strings
 * @str1: first string
 * @str2: second string
 *
 * Return: the difference of the two strings
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str2[i] != '\0')
			break;
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 * _strcat - concatenates the path with '/' and the command(strc2)
 * @path: first string
 * @command: second string
 * Return: pointer
 */
char *_strcat(char *path, char *command)
{
	char *str_new;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (path == NULL)
		len1 = 0;
	else
	{
		/* find the length of path token*/
		for (len1 = 0; path[len1]; len1++)
			;
	}
	if (command == NULL)
		len2 = 0;
	else
	{
		/* find the length of command typed*/
		for (len2 = 0; command[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2; /* 2 to cater for '/' and '\0' */

	str_new = malloc(newlen * sizeof(char));
	if (str_new == NULL)
	{
		printf("Error: malloc() in _strcat()");
		return (NULL);
	}

	for (i = 0; i < len1; i++)
		str_new[i] = path[i];
	str_new[i] = '/';
	for (j = 0; j < len2; j++)
	{
		str_new[i + 1 + j] = command[j];
	}
	str_new[newlen - 1] = '\0';

	return (str_new);
}
