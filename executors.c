#include "shell.h"

int execute_command(char **args, char **env)
{
	pid_t pid;

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

	return (0);
}
Déclarer la variable status
Dans le processus Parent (pid > 0):
    Attendre la fin de l'enfant avec waitpid(pid, &status, 0)
    Si l'enfant s'est terminé normalement (WIFEXITED):
        Extraire le code de retour avec WEXITSTATUS(status)
        Retourner ce code de retour