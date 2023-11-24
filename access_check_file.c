#include "main.h"

/**
 * access_check - checks file access
 * @arg: command arg
 * @cmd: command arg
 * @err: error string
 * @c: count of command
 *
 * Return : 0 if successful, 1 if otherwise
 */

int access_check(char **arg, char *cmd, char *err, int c, char **e)
{
	int idcheck;
	char *p;

	if (cmd == NULL)
	{
		p = arg[0];
	}
	else
	{
		p = cmd;
	}

	if (access(p, X_OK) == 0)
	{
		idcheck = fork();

		if (idcheck == 0)
		{
			_execve(p, arg, e);
		}
		
		else
		{
			wait(NULL);
		}

		return (0);
	}

	else
	{
		_perror(err, c, p);
		return (1);
	}
}
