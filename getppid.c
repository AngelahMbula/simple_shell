#include "main.h"

/**
 * main - Gets the current process ppid
 * Return: 0 Always a success
 */

int main(void)
{
	pid_t cur_ppid;

	cur_ppid = getppid();
	printf("%u\n", cur_ppid);
	return (0);
}
