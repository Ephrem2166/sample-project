#include "main.h"

/**
 * cmd_err - function prints error if command not found
 * @cmd1: pointer to name of caller
 * Return: 0
 */

void cmd_err(char *cmd1)
{

	/* Not good practice, find a way to use less sys call */
	write(STDERR_FILENO, cmd1, _strlen(cmd1));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ": not found\n", 13);
}

/**
 * exe_err - returns error if command cant be executed
 * @command: pointer to command
 */

void exe_err(char *command)
{
	perror(command);
}
