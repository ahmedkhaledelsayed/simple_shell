#include "shell.h"
/**
 * _values_path - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _values_path(char **arg, char **env)
{
	char *token = NULL, *relative_path = NULL, *absolute_path = NULL;
	size_t pathvalue, command;
	struct stat statusofptr;

	if (stat(*arg, &statusofptr) == 0)
		return (-1);
	relative_path = path_func(env);
	if (!relative_path)
		return (-1);
	token = _strtok(relative_path, ":");
	command = _strlen(*arg);
	while (token)
	{
		pathvalue = _strlen(token);
		absolute_path = malloc(sizeof(char) * (pathvalue + command + 2));
		if (!absolute_path)
		{
			free(relative_path);
			return (-1);
		}
		absolute_path = _strcpy(absolute_path, token);
		_strcat(absolute_path, "/");
		_strcat(absolute_path, *arg);

		if (stat(absolute_path, &statusofptr) == 0)
		{
			*arg = absolute_path;
			free(relative_path);
			return (0);
		}
		free(absolute_path);
		token = _strtok(NULL, ":");
	}
	free(relative_path);
	return (-1);
}
