#include "shell.h"
/**
 * _fork - function that create a fork
 *@arg: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t c;
	int stat;
	char *format = "%s: %d: %s: not found\n";

	c = fork();

	if (c == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&stat);

		if (WIFEXITED(stat) && WEXITstat(stat) != 0)
			return (WEXITstat(stat));
	}
	return (0);
}
