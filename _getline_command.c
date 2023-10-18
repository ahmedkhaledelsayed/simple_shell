#include "shell.h"
/**
 * _getline - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline(void)
{
	char *lineptr = NULL;
	size_t input_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &input_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
