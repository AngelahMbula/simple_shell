#include "main.h"

/**
 * main - Prints values
 * @ac - Number of args
 * @av - Null terminated array of strings
 *
 * Return: 0 Always Success
 */

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 0)
		return (1);

	while (*(av)[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
