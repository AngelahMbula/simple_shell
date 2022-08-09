#include "shell.h"
/**
 * sh_launch - starting process using sys calls are initiated
 * @args: pointer to command line argument
 * Return: 1 on success
 */
int sh_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("sh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("sh");
    }
    else
    {
        do {
           pid_t wpid = waitpid(pid_t pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}