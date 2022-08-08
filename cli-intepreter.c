#include "main.h"

#define _EOF (-1)

/**
 * main - main function for simple shell
 * @argc: unused parameter
 * @argv: double pointer to argument vector
 * @env: dbl pointer to environment vector
 * Return: Exit on success.
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *readline = NULL;
	char **arrtok;
	char *PRGM = argv[0];
	int EXIT_CODE, input_c = 0;
	size_t n = 0;
	ssize_t rd = 0;

	for (;;) /* loop endlessly until exit */
	{
		if (isatty(STDIN_FILENO)) /* print prompt */
			_puts("$ ");
		rd = getline(&readline, &n, stdin);
		if (rd == _EOF)
		{
			free(readline), exit(EXIT_CODE); /*recieve exit status */
		}
		if (readline[input_c] == '\n') /* handling empty inputs */
		{
			continue;
			input_c++;
		}
		arrtok = tokenize(readline); /* split input into array of strings */
		if (_strcmp(arrtok[0], "exit") == 0)
		{
			free(readline), free(arrtok);
			return (EXIT_CODE);
		}
		if (_strcmp(arrtok[0], "env") == 0)
		{
			_env(env, arrtok);
			continue;
		}
		if (arrtok != NULL)
		{
			EXIT_CODE = exec(arrtok, PRGM, readline, env);
			free(arrtok);
		}
	}
	free(readline), free(arrtok);
	return (0);
}
