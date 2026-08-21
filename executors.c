#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a binary with its arguments in a child process
 * @path: Absolute or relative path to the executable file
 * @args: Array of argument strings (starting with command name)
 * @env: Environment variables array
 *
 * Return: Exit status of the child process, or -1 on failure
 */
int execute_command(char *path, char **args, char **env)
{
	pid_t pid;
	int status;
    int wstatus;

	if (path == NULL || args == NULL || args[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(path, args, env) == -1)
		{
			perror(path);
			_exit(127);
		}
	}
	else
	{
		waitpid(pid, &wstatus, 0);

		if (WIFEXITED(wstatus))
			status = WEXITSTATUS(wstatus);
	}

	return (status);
}
