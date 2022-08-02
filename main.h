#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern int EXIT_CODE;
extern int errno;

/* write functions */
int _putchar(char c);
void _puts(char *s);

/* string functions */

int _strlen(char *s);
int _strcmp(char *str1, char *str2);
char *_strdup(char *src);
char *_strcat(char *dest, char *src);

/* pid functions */

int pid(void);
int ppid(void);

/* main functions */

char *readarg(int EXIT_CODE);
char **tokenize(char *readline);
int _argleng(char *readline);
int exec(char *arrtok[], char *PRGM, char *readline, char **env);

/* Error functions */

void cmd_err(char *cmd1);
void exe_err(char *command);
void perm_denied(char *NAME);

/* path functios */

int path_size(char *path);
char **get_path(char **env);
ssize_t _getline(char *read, ssize_t rd, int fd);

/* environment functions */
void _env(char **env, char **arrtok);

#endif
