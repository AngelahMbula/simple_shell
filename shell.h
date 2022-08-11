#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ssp.h>
#include <sys/types.h>

#define EXIT -3
#define END_OF_FILE -2

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;
alias_t *aliases;

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;


/**
 * loop functions
 */
void sh_loop(void);
char *sh_read_line(void);
char **sh_split_line(char *line);
int sh_launch(char **args);
int sh_execute(char **args, char **front);
int sh_env(char **args, char __attribute__((__unused__)) **front);
int sh_alias(char **args, char __attribute__((__unused__)) **front);

/**
 * builtin functions and helper functions
 */
int sh_cd(char **args,  char __attribute__((__unused__)) **front);
int sh_exit(char **args, char **front);
int (*get_builtin(char *command))(char **args, char **front);
int sh_num_builtins();
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);
char *itoa(int num, char *buffer, int);
void sig_handler(int sig);
char **_getenv(const char *var);
char **copy_env(void);
void free_env(void);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
char **rep_alias(char **args);
void free_list(list_t *head);
void free_alias_list(alias_t *head);
void free_args(char **args, char **front);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *add_node_end(list_t **head, char *dir);
char *get_env_value(char *beginning, int len);
char *get_location(char *command);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);
char *get_pid(void);
void variable_replacement(char **line, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
char **replace_aliases(char **args);
int check_args(char **args);
void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_itoa(int num);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int proc_file_commands(char *file_path, int *exe_ret);
int cant_open(char *file_path);
char **_strtok(char *line, char *delim);
int execve(const char *pathname, char *const argv[], char *const envp[]);


int hist;
char *name;
extern char **environ;


#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>

#endif
