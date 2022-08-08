#include "main.h"

/**
 * path_len - gets the length of a path
 * @path: pointer to path
 * Return: length of path
 */

int path_len(char *path)
{
	int i, count;

	count = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '=' || path[i] == ':')
			count++;
		i++;
	}
	return (count);
}

/**
 * _env - env built-in prints the environment
 * @env: pointer to environment variable
 * @arrtok: pointer to arrtok
 * Return: nothing
 */

void _env(char **env, char **arrtok)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
		_putchar('\n');
	}
	free(arrtok);
}
