#include "shell.h"
#define SH_RL_BUFSIZE 4096
/**
 * sh_read_line - reads line from stdin
 * Return: void
 * 
 */
char *sh_read_line(void)
{
    int bufsize = SH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr,"sh:allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return (buffer);
        }
        else
        {
            buffer[position] = c;
        }
        position++;
        
        if (position >= bufsize)
        {
            bufsize += SH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
        if (!buffer)
        {
            fprintf(stderr,"sh:allocation error\n");
            exit(EXIT_FAILURE);
        }
        }
    }
}/**
 * @brief 
 * 
 */
char *get_args(char *line, int *exe_ret)
{
	size_t n = 0;
	ssize_t read;
	char *prompt = "$ ";

	if (line)
		free(line);

	read = _getline(&line, &n, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		return (get_args(line, exe_ret));
	}

	line[read - 1] = '\0';
	variable_replacement(&line, exe_ret);
	handle_line(&line, read);

	return (line);
}
