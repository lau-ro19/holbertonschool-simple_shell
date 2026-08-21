#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

char *get_path_env(void);
char *build_path(char *dir, char *command);
char *search_in_path(char *command);
char *read_command(void);
char *get_valid_path(char *command);
int execute_command(char *path, char **argv);
char **split_line(char *line);
void free_argv(char **argv);

#endif
