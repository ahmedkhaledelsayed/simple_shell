#include "shell.h"
/**
 * getline - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *getline(void)
{
	char *line_ptr = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&line_ptr, &char_user, stdin) == -1)
	{
		free(line_ptr);
		return (NULL);
	}

	return (line_ptr);
}
