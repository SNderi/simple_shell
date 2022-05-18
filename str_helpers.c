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
 * _strcat - concatenates two strings
 * @dest: base string
 * @src: string to concatenate to dest
 *
 * Return: address of new string
 */
char *_strcat(char *dest, char *src)
{
	char *new;
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);

	new = malloc(sizeof(char) * (dest_len + src_len + 1));
	_strcpy(new, dest);
	_strcpy(new + dest_len, src);
	new[dest_len + src_len] = '\0';
	return (new);
}
