#include "shell.h"
#define SH_TOK_BUFSIZE 64
#define SH_TOK_DELIM " \t\r\n\a"

/**
 * sh_split_line - parse the line into a list of arguments
 * @line: string of command
 * Return: array of tokens
 */
char **sh_split_line(char *line)
{
    int bufsize = SH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr,"sh:allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, SH_TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += SH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));

            if (!tokens)
            {
                fprintf(stderr,"sh:allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, SH_TOK_DELIM);
    }
    tokens[position] = '\0';
    return (tokens);
}