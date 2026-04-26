#include "shell.h"

/**
 * builtin_env - prints the current environment variables
 * @env: the array of environment variables
 */
void builtin_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
/**
 * builtin_exit - exit the shell
 * @args: the array of arguments
 * @env: the array of environment variable
 */
void builtin_exit(char **args, char **env)
{
	int status;

	(void)env;
	status = 0;
	if (args[1] != NULL)
		status = atoi(args[1]); /** convert in int */
	free(args);
	exit(status);

}
/**
 * check_builtin - checks if a command is a builtin and executes it
 * @args: the array of arguments
 * @env: the array of environment variables
 *
 * Return: 1 if builtin, 0 otherwise
 */
int check_builtin(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0) /**compare the string */
	{
		builtin_exit(args, env);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		builtin_env(env);
		return (1);
	}
	return (0);

}
