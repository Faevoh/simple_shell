#include "main.h"
/**
  *main - Mock-up instance of a shell interpreter
  *@argc: argument count
  *@argv: argument vector
  *Return: 0
  */
int main(int argc, char *argv[])
{
	char *sh_prompt = "s_shell $";
	char *lineptr = NULL;
	size_t l = 0;
	ssize_t userLine;
	char *args[MAX_ARGS];
	pid_t pid;
	int status, statusExit;
	char *envp[] = {NULL};
	char *path_finder;
	((void)argc), ((void)argv);

	while (1)
	{
		printf("%s", sh_prompt);
		userLine = getline(&lineptr, &l, stdin);
		if (userLine == -1)
		{
			printf("Leaving shell...\n");
			return (-1);
		}
		lineptr[strlen(lineptr) - 1] = '\0';
		cmdline(lineptr, args);
		if (strcmp(lineptr, "exit") == 0)
		{
			if (args[1] != NULL)
			{
				statusExit = atoi(args[1]);
				printf("exit %d\n", statusExit);
				exit(statusExit);
			}
			else
			{
				printf("exit\n");
				exit(0);
			}
		}
		if (strcmp(args[0], "env") == 0)
		{
			cmdEnv();
			continue;
		}
		if (strcmp(args[0], "cd") == 0)
		{
			cmd_cd(args[0]);
			continue;
		}
		path_finder = cmdPath(args[0]);
		if (path_finder == NULL)
		{
			printf("%s: command not found\n", args[0]);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(path_finder, args, envp) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}

	}

	free(lineptr);
	return (0);
}
