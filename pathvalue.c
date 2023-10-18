#include "shell.h"
/**
 * pathvalues - separate the paths.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int pathvalues(char **arg, char **env)
{
	char *token = NULL, *path_relative = NULL, *path_absolute = NULL;
	size_t valuepath, comman;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_relative = _get_path(env);
	if (!path_relative)
		return (-1);
	token = _strtok(path_relative, ":");
	comman = _strlen(*arg);
	while (token)
	{
		valuepath = _strlen(token);
		path_absolute = malloc(sizeof(char) * (valuepath + comman + 2));
		if (!path_absolute)
		{
			free(path_relative);
			return (-1);
		}
		path_absolute = _strcpy(path_absolute, token);
		_strcat(path_absolute, "/");
		_strcat(path_absolute, *arg);

		if (stat(path_absolute, &stat_lineptr) == 0)
		{
			*arg = path_absolute;
			free(path_relative);
			return (0);
		}
		free(path_absolute);
		token = _strtok(NULL, ":");
	}
	free(path_relative);
	return (-1);
}
