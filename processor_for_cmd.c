#include "main.h"

/**
 * process_command - process the command and execute correctly
 *
 * @argv: array of strings where argv[0] is the command
 * Return: 0 if successful and 1 if not
 */
int process_command(char **argv)
{
	int numArg = num_args(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (numArg == 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	else if (_strcmp(argv[0], "setenv" == 0)
	{
		if (numArg == 3)
		{
			_setenv(argv[1], argv[2]);
			return 0;
		}
	else if (_strcmp(argv[0], "unsetenv" == 0)
	{
		if (numArg == 2)
		{
			_setenv(argv[1]);
			return (0);
		}
	}
