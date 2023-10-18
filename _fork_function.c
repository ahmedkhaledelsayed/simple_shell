#include "shell.h"
/**
 * fork_create - function that create a fork
 *@arg: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int fork_create(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t sub;
	int status;
	char *format = "%s: %d: %s: not found\n";

	sub = fork();

	if (sub == 0)
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
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
