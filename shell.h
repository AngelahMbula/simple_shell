#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/wait.h"

/**
 * loop functions
 */
void sh_loop(void);
char *sh_read_line(void);
char **sh_split_line(char *line);
int sh_launch(char **args);
int sh_execute(char **args);

/**
 * builtin functions
 */
int sh_cd(char **args);
int sh_exit(char **args, char **front);
char *builtin_str;
int (*builtin_func)(char **);
int sh_num_builtins();

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif