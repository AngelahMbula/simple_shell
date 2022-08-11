
#include "shell.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
/**
 * error_env - Creates an error message for sh_env errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_env(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	len = strlen(name) + strlen(hist_str) + strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	strcpy(error, name);
	strcat(error, ": ");
	strcat(error, hist_str);
	strcat(error, ": ");
	strcat(error, args[0]);
	strcat(error, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (error);
}

/**
 * error_1 - Creates an error message for sh_alias errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_1(char **args)
{
	char *error;
	int len;

	len = strlen(name) + strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	strcpy(error, "alias: ");
	strcat(error, args[0]);
	strcat(error, " not found\n");

	return (error);
}

/**
 * error_2_exit - Creates an error message for sh_exit errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_exit(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = strlen(name) + strlen(hist_str) + strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	strcpy(error, name);
	strcat(error, ": ");
	strcat(error, hist_str);
	strcat(error, ": exit: Illegal number: ");
	strcat(error, args[0]);
	strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_cd - Creates an error message for shellby_cd errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_cd(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	len = strlen(name) + strlen(hist_str) + strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	strcpy(error, name);
	strcat(error, ": ");
	strcat(error, hist_str);
	if (args[0][0] == '-')
		strcat(error, ": cd: Illegal option ");
	else
		strcat(error, ": cd: can't cd to ");
	strcat(error, args[0]);
	strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_syntax - Creates an error message for syntax errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_syntax(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = strlen(name) + strlen(hist_str) + strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	strcpy(error, name);
	strcat(error, ": ");
	strcat(error, hist_str);
	strcat(error, ": Syntax error: \"");
	strcat(error, args[0]);
	strcat(error, "\" unexpected\n");

	free(hist_str);
	return (error);
}