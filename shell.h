#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* environ - the environment, used to access the PATH variable */
extern char **environ;

char *read_command(void);
char *get_path_env(void);
char *build_path(char *dir, char *command);
char *get_valid_path(char *command);
int execute_command(char *path, char **args, char **env);
int check_builtin(char **args, char **env);
char *search_in_path(char *command);
char **split_line(char *line);
int process_line(char *line, char *prog_name, int line_num, int *status);
void print_prompt(void);
void free_argv(char **argv);

#endif
