#include "main.h"

extern char **environ;

/**
  *cmdEnv - handling the env builtin
  */

void cmdEnv(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
