#include "main.h"

/**
  *_exec - Handle commandline arguments
  *and execute commands
  *@cmmand: command input
  *@argv: argument input
  *Return: 0.
  */

void _exec(char *cmmand, char *argv[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(cmmand, argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
