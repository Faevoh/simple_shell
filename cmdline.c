#include "main.h"

/**
  *cmdline - Handling command line
  *argument without strtok()
  *@cmmand: target inputs
  *@args: arguments
  *Return: 0
  */

void cmdline(char *cmmand, char **args)
{
	int a = 0;
	char *rm_token;

	while (a < MAX_ARGS && (rm_token = _strsep(&cmmand, " \t\n")) != NULL)
	{
		if (*rm_token != '\0')
		{
			args[a] = rm_token;
			a++;
		}
	}

	args[a] = NULL;

}
