#include "shell.h"
/**
 * sh_cd - function that changes directory
 * sh_exit- function that exits
 * @args: command line arguments
 * Return: 1, 0 on success
 */
char *builtin_str= {
    "cd",
    "exit"
};
int (*builtin_func)(char **) = {
    &sh_cd,
    &sh_exit
};
int sh_num_builtins() {
    return (sizeof(builtin_str) / sizeof(char *));
    }

int sh_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr,"sh:expected argument to \"cd \"\n");
    } else {
        if (chdir(args[1] != NULL)) {
            perror("sh");
        }
    }
    return (1);
}

int sh_exit(char **args, char **front)
{
    int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, front);
	exit(num);
}