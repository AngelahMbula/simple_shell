#include "shell.h"
/**
 * sh_loop - print a prompt, call a function to read a line, call function to split line into
 * args and execute args
 */
void sh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = sh_read_line();
        args = sh_split_line(line);
        status = sh_execute(args);

        free(line);
        free(args);
    } while(status);
}