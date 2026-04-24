#include "shell.h"
/**
 * get_path - find the PATH variable in the environment
 * @env: the array of environment variables
 *
 * Return: the PATH value or NULL if not found
 */
char *get_path(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * find_path - finds the full path of a command
 * @command: the command to find
 * @env: the array of environment variables
 *
 * Return: the full path of the command or NULL if not found
 */
char *find_path(char *command, char **env)
{
	char *path_env;
	char *path_copy;
	char *token;
	char *full_path;

	path_env = get_path(env);
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);

}
