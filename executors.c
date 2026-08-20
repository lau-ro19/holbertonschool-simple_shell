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

	return (0);
}
Si pid == 0 (Processus Enfant):
    Tenter d'exécuter args[0] avec execve(args[0], args, env)
    Si execve échoue:
        Afficher l'erreur avec perror(args[0])
        Quitter le processus enfant avec _exit(127)