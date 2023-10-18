#include "shell.h"
/**
 * _path_v - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _path_v(char **arg, char **env)
{
	char *token = NULL, *relative_path = NULL, *absolute_path = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	relative_path = _get_path(env);
	if (!relative_path)
		return (-1);
	token = _strtok(relative_path, ":");
	command = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		absolute_path = malloc(sizeof(char) * (value_path + command + 2));
		if (!absolute_path)
		{
			free(relative_path);
			return (-1);
		}
		absolute_path = _strcpy(absolute_path, token);
		_strcat(absolute_path, "/");
		_strcat(absolute_path, *arg);

		if (stat(absolute_path, &stat_lineptr) == 0)
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
