#include "main.h"

/**
  *_exec - Handle commandline arguments
  *and execute commands
  *@cmmand: command input
  *@args: argument input
  *Return: 0.
  */

void _exec(char *cmmand, char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(cmmand, args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
