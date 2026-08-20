#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a command in a child process
 * @args: Array of argument strings (command name and flags)
 * @env: Environment variables array
 *
 * Return: Exit status of the child process, or -1 on failure
 */
int execute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	if (args == NULL || args[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			_exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
