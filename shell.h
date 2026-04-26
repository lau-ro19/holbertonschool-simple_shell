#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>


/* main.c*/
int main(int argc, char **argv, char **env);
void run_command(char *line, char **env, char *prog_name, int count);

/*parser.c*/
char *read_line(void);
char **tokenize(char *line);

/*executor.c*/
int executor(char *path, char **args, char **env);

/*path.c*/
char *find_path(char *command, char **env);
char *get_path(char **env);

/*builtin.c*/
void builtin_exit(char **args, char **env, char *line);
void builtin_env(char **env);
int check_builtin(char **args, char **env, char *line);


#endif
