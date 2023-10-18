#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *path_func(char **env);
int _values_path(char **arg, char **env);
char *getline_func(void);
void _getenv(char **env);
char **token_func(char *lineptr);
void exit_func(char **args, char *lineptr, int exit);
int fork_create(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);


#endif /* SHELL_H */
