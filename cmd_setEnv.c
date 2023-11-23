#include "main.h"

/**
 * print_list - prints the contents of the s..linked list
 * @head: head of the s..linked list
 */
void print_list(struct Node *head)
{
	struct Node *current = head;

	while (current)
	{
		write(STDOUT_FILENO, current->str, _strlen(current->str));
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}

/**
 * free_list - free up memory allocated for each node in the s..linked list
 * @head: head of the s..linked list
 */
void free_list(struct Node *head)
{
	struct Node *current = head;

	while (current)
	{
		struct Node *next = current->next;

		free(current);
		current = next;
	}
}

/**
 * _env - prints the environment variable
 * Return: always 0
 */
int _env(void)
{
	struct Node *head = NULL;
	char **env = environ;

	while (*env != NULL)
	{
		add_node(&head, new_node(*env));
		env++;
	}
	print_list(head);
	free_list(head);

	return (0);
}

/**
 * _setenv - set environment variable
 * @name: name of environmnet
 * @value: set  value
 *
 * Return: always 0
 */
void update_environ(struct Node *head);

int _setenv(const char *name, const char *value)
{
	char **env = environ;
	struct Node *head = NULL;

	while (*env != NULL)
	{
		add_node(&head, new_node(*env));
		env++;
	}

	add_env_var(&head, name, value);

	update_environ(head);

	free_list(head);
	return (0);
}

/**
 * _unsetenv - deletes an environment varuaible
 * @name: name of the environment variable to delete
 *
 * Return: 0 if successful, otherwise -1 on failure
 */
int _unsetenv(const char *name)
{
	char **current = environ;
	char *temp = *current++;
	size_t len = _strlen(name);

	while (*current != NULL)
	{
		if (_strncmp(*current, name, len) == 0 && (*current)[len] == '=')
		{
			while (*current != NULL)
			{
				*(current++) = temp;
				temp = *current++;
			}
			return (0);
		}
		current++;
	}
	return (-1);
}
