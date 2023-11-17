#include "main.h"

/**
  *main - Mock-up instance of a shell interpreter
  *@argc: argument count
  *@argv: argument vector
  *@envp: environ variable
  *Return: 0
  */

int main(int argc, char *argv[])
{
	char *sh_prompt = "s_shell $ ";
	char *readLine = NULL;
	size_t lineSize;
	char *args[MAX_ARGS];
	((void)argc), ((void)argv);

	while (1)
	{
		printf("%s", sh_prompt);
		if (_getLine(&readLine, &lineSize, stdin) == -1)
		{
			printf("Leave Shell....\n");
			break;
		}
		readLine[_strlen(readLine) - 1] = '\0';
		cmdline(readLine, args);
		_exec(args[0], args);
	}

	free(readLine);
	return (0);
}
