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
int count;

(void)argc;
(void)argv;

count = 0;

while (1) /** infinite loop */
{

	if (isatty(STDIN_FILENO)) /** check if terminal? */
	write(1, "$ ", 2);

	line = read_line(); /**read line of user, call getline*/
	if (line == NULL)  /** if NULL EOF */
	{
		free(line);
		exit(0);
	}

	if (line[0] == '\n') /**user entry without nothing */
	{
		free(line);
		continue;
	}
	run_command(line, env, argv[0], count);
}
return (0);
}

/**
 * run_command - parses and executes a command
 * @line: the command line read from the user
 * @env: the array of environment variables
 * @prog_name: name of program
 * @count: the command line counter
 *
 * Return: void
 */
void run_command(char *line, char **env, char *prog_name, int count)
{
	char **args;
	char *path;

	args = tokenize(line); /** tokenize in array */
	if (args == NULL || args[0] == NULL) /** malloc fail or only whitespace */
	{
		free(line);
		free(args);
		return;
	}

	if (check_builtin(args, env, line)) /**check if exit or env */
	{
		return;
	}

	path = find_path(args[0], env); /** search full_path */

	if (path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prog_name, count, args[0]);
		free(line);
		free(args);
		return;
	}

	executor(path, args, env); /** fork + execve + wait */

	free(line);
	free(args);
	free(path);

}
