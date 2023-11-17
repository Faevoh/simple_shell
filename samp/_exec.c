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
	char *full_Path = cmdPath(cmmand);
	pid_t pid;

	if (full_Path != NULL)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(full_Path, args, NULL) == -1)
			{
				perror(full_Path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
		free(full_Path);
	}
	else
	{
		printf("%s: No such file or directory\n", cmmand);
	}
}
