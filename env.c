#include "shell.h"
/**
 * sh_env - prints current env
 * @args: pointer to array of command line arguments
 * 
 * Return: 0, -1 if error occurs
 */
int sh_env(char **args, char __attribute__((__unused__)) **front)
{
    int index;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}
/**
 * get_env - Get the env object from PATH
 * 
 * @var: pointer to the env variable 
 * Return: pointer to the env variable, otherwise NULL
 */
char **_getenv(const char *var)
{
    int index, len;

	len = strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
/**
 * copy_env - makes copy of the environment
 * Return: pointer to the copy, otherwise NULL
 * 
 */
char **copy_env(void)
{
    char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(strlen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		strcpy(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}
/**
 * get_env_value - gets value of an env variable
 * @beginning: env variable being searched for
 * @len: length of env variable
 * Return: value of env variable
 */
char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	strncat(var, beginning, len);

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=')
			temp++;
		temp++;
		replacement = malloc(strlen(temp) + 1);
		if (replacement)
			strcpy(replacement, temp);
	}

	return (replacement);
}
/**
 * free_env - frees memory taken up by env
 * 
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}