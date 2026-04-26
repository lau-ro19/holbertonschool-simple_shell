#include"shell.h"

/**
 * executor - Executes a command with given arguments and environment.
 * @path: Path to the command.
 * @args: Arguments for the command.
 * @env: Environment variables.
 */

int executor(char *path, char **args, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }
    if (pid == 0)
    {
        execve(path, args, env);
        perror("execve");
        exit(127);
        
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}
