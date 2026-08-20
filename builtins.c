#include "shell.h"
#include <stdlib.h>
#include <string.h>

int check_builtin(char **args, char **env)
{
	(void)env;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(0);
	}

	return (0);
}
Comparer args[0] avec la chaîne "env" si args[0] est égal à "env":
    - Parcourir le tableau de variables d'environnement
    - Afficher chaque variable suivie d'un saut de ligne '\n'
    - Retourner 1 (indique que la commande était un builtin et a été exécutée)