#include "shell.h"
/**
 * path_func - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *path_func(char **env)
{
	size_t index_path = 0, var = 0, counter = 5;
	char *path = NULL;

	for (index_path = 0; _strncmp(env[index_path], "PATH=", 5); index_path++)
		;
	if (env[index_path] == NULL)
		return (NULL);

	for (counter = 5; env[index_path][var]; var++, counter++)
		;
	path = malloc(sizeof(char) * (counter + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, counter = 0; env[index_path][var]; var++, counter++)
		path[counter] = env[index_path][var];

	path[counter] = '\0';
	return (path);
}
