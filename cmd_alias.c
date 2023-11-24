#include "main.h"

/**
 * init_aliases - initializes the aliases with some std values
 * @aliases: head of the s..linked list of the aliases
 */
void init_aliases(alias_t **aliases)
{
	set_alias(aliases, "l", "ls -CF");
	set_alias(aliases, "la", "ls -A");
	set_alias(aliases, "ll", "ls -aLF");
	set_alias(aliases, "ls", "ls --color=auto");
}

/**
 * alias_command - alias command
 * @argv: argument
 * @num_arg: number of arguments
 *
 * Return: 0 if successful
 */
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)))
{
	static alias_t *aliases;
	static int initialized = 0;
	int i;
	char *name, *value;

	if (!initialized)
	{
		init_aliases(&aliases);
		initialized = 1;
	}

	if (_strcmp(argv[0], "alias") != 0)
	{
		return (0);
	}

	if (num_arg == 1)
	{
		print_all_aliases(aliases);
		return (1);
	}

	for (i = 1; i < num_arg; i++)
	{
		name = argv[i];
		value = _strchr(argv[i], '=');

		if (value)
		{
			*value = '\0';
			value++;

			if (*value == '\0')
			{
				continue;
			}
			set_alias(&aliases, name, value);
		}
		else
		{
			print_alias(aliases);
		}
	}
	return (1);
}

/**
 * set_alias - sets alias
 * @alaises: head of the s..linked list of aliases
 * @name: name of alias
 * @value: value of alias
 */
void set_alias(alias_t **aliases, char *name, char *value)
{
	alias_t *currentAlias = *aliases;
	alias_t *alias = NULL;

	while (currentAlias)
	{
		if (_strcmp(currentAlias->name, name) == 0)
		{
			alias = currentAlias;
			break;
		}

		currentAlias = currentAlias->next;
	}

	if (alias)
	{
		free(alias->value);
		alias->value = _strdup(value);
	}
	else
	{
		alias = malloc(sizeof(alias_t));
		if (!alias)
		{
			return;
		}

		alias->name = _strdup(name);
		alias->value = _strdup(value);
		alias->next = *aliases;
		*aliases = alias;
	}

	free(alias);
}

/**
 * print_alias - prints an alias
 * @alias: alias to print
 */
void print_alias(alias_t *alias)
{
	write(STDOUT_FILENO, "alias ", 6);
	write(STDOUT_FILENO, alias->name, _strlen(alias->name));

	if (alias->value[0] == '\'')
	{
		write(STDOUT_FILENO, "=", 1);
	}
	else
	{
		write(STDOUT_FILENO, "='", 2);
	}

	write(STDOUT_FILENO, alias->value, _strlen(alias->value));

	if (alias->value[_strlen(alias->value) - 1] == '\'')
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		write(STDOUT_FILENO, "'\n", 2);
	}
}
