#include "main.h"

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
