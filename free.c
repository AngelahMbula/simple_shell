#include "shell.h"
/**
 * free_list - frees list_t list
 * @head: beginning of list
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
/**
 * free_alias_list - frees a alias_t list
 * @head: pointer to beginning of list
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
/**
 * free_args - frees up memory taken by args
 * @args: pointer to command line arguments
 * @front: pointer to beginning of args
 * 
 */
void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}
