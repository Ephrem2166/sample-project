#include "main.h"

#define DELIM " \n\t\v\a"

/**
 * _argleng - splits getline result into vector of strings
 * @readline: resulting string form getline
 * Return: arg length
 */

int _argleng(char *readline)
{
	int args = 1;
	int i = 0;
	int cmd1 = 0;

	while (readline[i] != '\0' && readline[i] != '\n')
	{
		if (readline[i] != ' ')
			cmd1 = 1;
		if (readline[i] == ' ' && readline[i + 1] != ' '
		    && readline[i + 1] != '\n' && cmd1 == 1)
			args++;
		i++;
	}
	return (args);
}

/**
 * tokenize - function splits command line input into tokens
 * @readline: pointer to command line input
 * Return: double pointer to array of tokens
 */

char **tokenize(char *readline)
{
	int i = 0;
	int bufsize;
	char **arrtok;
	char *tok;

	bufsize = _argleng(readline);
	arrtok = malloc((bufsize + 1) * sizeof(char *));

	if (arrtok == NULL)
	{
		free(arrtok);
		return (NULL);
	}
	tok = strtok(readline, DELIM);

	while (tok != NULL && i <= bufsize)
	{
		arrtok[i] = tok;
		i++;
		tok = strtok(NULL, DELIM);
	}
	arrtok[i] = NULL;
	return (arrtok);
}
