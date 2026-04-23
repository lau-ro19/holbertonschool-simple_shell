#include"shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Argument vector (array of strings).
 * @env: Environment variables.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv, char **env)
{
char *line;
char **args;
char *path;

(void)argc;
(void)argv;

while (1)
{

	if (isatty(STDIN_FILENO))
	write(1, "$ ", 2);

	line = read_line();
	if (line == NULL)
	{
		free(line);
		exit(0);
	}

	if (line[0] == '\n')
	{
		free(line);
		continue;
	}
	run_command(line, env);
}
return (0);
}

/**
 * run_command - parses and executes a command
 * @line: the command line read from the user
 * @env: the array of environment variables
 *
 * Return: void
 */
void run_command(char *line, char **env)
{
	char **args;
	char *path;

	args = tokenize(line);

	if (check_builtin(args, env))
	{
		free(line);
		free(args);
		continue;
	}

	path = find_path(args[0], env);

	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		free(line);
		free(args);
		continue;
	}

	executor(path, args, env);

	free(line);
	free(args);
	free(path);

}

