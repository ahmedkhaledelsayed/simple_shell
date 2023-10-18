#include "shell.h"
/**
 * getline_func - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *getline_func(void)
{
	char *lineptr = NULL;
	size_t user_in = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &user_in, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
