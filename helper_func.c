#include "main.h"

/**
 * _strlen - returns length of string
 * @s: pointer to string
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings.
 * @str1: pointer to first string
 * @str2: pointer to second string
 * Return: 0 if strings are equal, else not equal.
 */

int _strcmp(char *str1, char *str2)
{
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (0);
	else
		return (*str1 - *str2);
}

/**
 * _strdup - duplicates source string
 * @src: pointer to source to be dupped.
 * Return: dup
 */

char *_strdup(char *src)
{
	int src_size;
	static char *dup;
	char *dup_offset;

	src_size = _strlen(src);
	dup = malloc(sizeof(char) * src_size + 1);
	if (dup == NULL)
		return (NULL);
	dup_offset = dup;
	while (*src)
	{
		*dup_offset = *src;
		dup_offset++;
		src++;
	}
	*dup_offset = '\0';
	return (dup);
}

/**
 * _strcat - concatenates source string to destination.
 * @dest: pointer destination string
 * @src: pointer to src string
 * Return: concatenated string.
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
		*ptr++ = *src++;
	ptr = '\0';
	return (dest);
}
