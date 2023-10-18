#include "shell.h"
/**
 * exit_fun - function that exits the shell
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void exit_fun(char **arg, char *lineptr, int _exit)
{
	int exit_stat = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	exit_stat = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 *env_fun - function to get env to be printed
 *@env: enviroment
 *Return: 0
 */

void env_fun(char **env)
{
	size_t r = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[r], _strlen(env[r]));
		write(STDOUT_FILENO, "\n", 1);
		r++;
	}
}
