#include "shell.h"

int execute_command(char **args, char **env)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	return (0);
}
Déclarer la variable pid
Appeler fork()
Si pid < 0 (échec de fork):
    Afficher une erreur avec perror
    Retourner (-1)