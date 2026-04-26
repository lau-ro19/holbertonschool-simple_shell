#include"shell.h"

/**
 * executor - Executes a command with given arguments and environment.
 * @path: Path to the command.
 * @args: Arguments for the command.
 * @env: Environment variables.
 */

void executor(char *path, char **args, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }

}