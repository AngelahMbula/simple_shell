#include "shell.h"
/**
 * main - function will loop and interpret commands
 * @argc: number of commands
 * @argv: argument vector
 * Return: EXIT_SUCCESS
 * 
 */
int main(*args)
{
    /**
     * run command loop
     */
    sh_loop();

    return (EXIT_SUCCESS);
}