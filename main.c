#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **input_command = NULL;
	int path_value = 0, exit = 0, n = 0;
	(void)ac;

	while (1)
	{
		getcommand = getline_func();
		if (getcommand)
		{
			path_value++;
			input_command = token_func(getcommand);
			if (!input_command)
			{
				free(getcommand);
				continue;
			}
			if ((!_strcmp(input_command[0], "exit")) && input_command[1] == NULL)
				exit_func(input_command, getcommand, exit);
			if (!_strcmp(input_command[0], "env"))
				_getenv(env);
			else
			{
				n = _values_path(&input_command[0], env);
				exit = fork_create(input_command, av, env, getcommand, path_value, n);
				if (n == 0)
					free(input_command[0]);
			}
			free(input_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit);
		}
		free(getcommand);
	}
	return (exit);
}
