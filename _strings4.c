#include "main.h"

/**
 * _strncpy - string copy of n limit
 * @dest: description
 * @src: source string
 * @size: number of char to be copied
 *
 * Return: size of char copied
 */
int _strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

/**
 * _1exit - exit with a status code
 * @status: status code to exit with
 * @c: count of command
 * @a: name of shell
 * @ag: string of input command
 *
 * Return: exit code
 */
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag)
{
	int i = ex_code;
	int j = 0;

	if (status != NULL)
	{
		while (status[j] != '\0')
		{
			if (!(status[j] > 47 && status[j] < 58))
			{
				_perrore(a, c, ag[0], ag[1]);
				ex_code = 2;
				return (500);
			}
			j++;
		}
		i = _atoi(status);
	}

	return (i);
}

/**
 * add_env_var - Add a new environment varuable to the linked list
 *
 * @head: pointer to head of linked list
 * @name: name of environment variable
 * @value: value if environment variable
 */
void add_env_var(struct Node **head, const char *name, const char *value)
{
}

/**
 * updt_env - update the eviron variable wiht yhe llinked lists content
 *
 * @head: head of the linked list
 */
void updt_env(struct Node *head)
{
}