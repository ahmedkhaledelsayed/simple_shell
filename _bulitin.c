#include "shell.h"
/**
 * exit_func - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @exit: value of exit
 * Return: None
 */
void exit_func(char **arg, char *lineptr, int exit)
{
	int status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(exit);
	}
	status = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(status);
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *Return: 0
 */

void _getenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
