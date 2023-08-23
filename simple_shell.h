#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*header  files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>

/* constants */
#define BUFFER_SIZE 1024
#define TOKEN_DELIM "\t\r\n\a"
#define ARG_MAX 4096
#define AND 1
#define OR 2

/* function prototypes */
void prompt (void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
void panic(char *message);
int cd_builtin(char **args);
int piping(char **args1, char **args2);
/*int env_builtin(void);*/
/*char *_getenv(const char *name);*/
int env_builtin(char **args);
/*int setenv_builtin(char **args);*/
/*int unsetenv_builtin(char **args);*/
/*int alias_builtin(char **args);*/
int exit_status(char **args);
/*int run_script(char *filename);*/
int launch(char **args);
int file_input(char *filename);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int echo_builtin(char **args);
char *getpid_string(void);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int logical(char **args);
extern char **environ;
size_t string_length(const char *str);
void handle_error_and_exit(char *error_message);

#endif
