#include "shell.h"
/**
 * _path_v - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _path_v(char **arg, char **env)
{
	char *token = NULL, *relativepath = NULL, *absolutepath = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	relativepath = _get_path(env);
	if (!relativepath)
		return (-1);
	token = _strtok(relativepath, ":");
	command = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		absolutepath = malloc(sizeof(char) * (value_path + command + 2));
		if (!absolutepath)
		{
			free(relativepath);
			return (-1);
		}
		absolutepath = _strcpy(absolutepath, token);
		_strcat(absolutepath, "/");
		_strcat(absolutepath, *arg);

		if (stat(absolutepath, &stat_lineptr) == 0)
		{
			*arg = absolutepath;
			free(relativepath);
			return (0);
		}
		free(absolutepath);
		token = _strtok(NULL, ":");
	}
	free(relativepath);
	return (-1);
}
