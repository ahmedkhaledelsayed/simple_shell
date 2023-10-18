#include "shell.h"
/**
 * get_path - get variable PATH.
 * @env: vhar to enviroment
 * Return: value of PATH.
 */

char *get_path(char **env)
{
	size_t i = 0, var = 0, counter = 5;
	char *path = NULL;

	for (i = 0; _strncmp(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);

	for (counter = 5; env[i][var]; var++, counter++)
		;
	path = malloc(sizeof(char) * (counter + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, counter = 0; env[i][var]; var++, counter++)
		path[counter] = env[i][var];

	path[counter] = '\0';
	return (path);
}
