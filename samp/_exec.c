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
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmmand, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			do {
				wpid = waitpid(pid, &status, WUNTRACED);
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status))
			{}
		}
	}
}
