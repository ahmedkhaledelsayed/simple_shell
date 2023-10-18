#include "shell.h"
/**
 * fork_fun - function to create a fork
 *@arg: char to command and values path
 *@av: char to the name of our program
 *@env: char to environment
 *@lineptr: char to command line
 *@np: int to id 
 *@c: int to Checker add new test
 *Return: 0 success
 */

int fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t c;
	int stat;
	char *format_ptr = "%s: %d: %s: not found\n";

	c = fork();

	if (c == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format_ptr, av[0], np, arg[0]);
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

		if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
			return (WEXITSTATUS(stat));
	}
	return (0);
}
