#include "shell.h"
/**
 * num_len - counts num
 * @num: number to be counted
 * Return: length of num 
 */
int num_len(int num)
{
    unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}
/**
 * create_error - write error message to stderr
 * @args: command line arguments
 * @err: error value
 * Return: the error value
 * 
 */
int create_error(char **args, int err)
{
    char *error;

	switch (err)
	{
	case -1:
		error = error_env(args);
		break;
	case 1:
		error = error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error = error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error = error_2_syntax(args);
		else
			error = error_2_cd(args);
		break;
	case 126:
		error = error_126(args);
		break;
	case 127:
		error = error_127(args);
		break;
	}
	write(STDERR_FILENO, error, strlen(error));

	if (error)
		free(error);
	return (err);
}