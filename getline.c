#include "shell.h"
/**
 * _getline - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline(void)
{
	char *line_ptr = NULL;
	size_t input = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&line_ptr, &input, stdin) == -1)
	{
		free(line_ptr);
		return (NULL);
	}

	return (line_ptr);
}
