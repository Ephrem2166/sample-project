#include "main.h"

/**
 * exec - fork exec and wait function
 * @arrtok: pointer array of tokens.
 * @PRGM: pointer to shell name
 * @readline: pointer to user input
 * @env: dbl ptr to environment vector
 * Return: integers (status);
 */

int exec(char *arrtok[], char *PRGM, char *readline, char **env)
{
	pid_t pid = fork();
	char *cmd = arrtok[0];
	int status = 0;
	int EXIT_CODE = 0;

	if (pid < 0)
	{
		perror(PRGM);
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* if child process */
	{
		if ((execve(cmd, arrtok, env) == -1)) /* only returns on error */
		{
			exe_err(cmd); /* perror if cmd can't execute */
			free(arrtok);
			free(readline);
			EXIT_CODE = 126;
			_exit(EXIT_CODE);
		}
		_exit(EXIT_SUCCESS);
	}
	/* wait for terminated children */

	waitpid(pid, &status, WEXITSTATUS(status)); /*Return exit stat of child */
	EXIT_CODE = WEXITSTATUS(status);
	return (EXIT_CODE); /*Return exit_code */
}
