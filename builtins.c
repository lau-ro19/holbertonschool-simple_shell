#include "shell.h"

int check_builtin(char **args, char **env)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	return (0);
}
omparer args[0] avec la chaîne "exit" si args[0] est égal à "exit":
    - Libérer la mémoire allouée si nécessaire
    - Quitter le programme immédiatement avec exit(0)