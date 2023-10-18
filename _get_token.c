#include "shell.h"
/**
 * token_func - get token of string
 * @lineptr: comman user
 * Return: To a pointer
 */

char **token_func(char *lineptr)
{
	char **command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	command = malloc(sizeof(char *) * (size + 2));
	if (command == NULL)
		return (NULL);

	token = _strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	command[i] = NULL;
	return (command);
}
