#include "main.h"

/**
  *main - Mock-up instance of a shell interpreter
  *@argc: argument count
  *@argv: argument vector
  *Return: 0
  */

int main(int argc, char *argv[])
{
	char *sh_prompt = "s_shell $ ";
	char *readLine;
	size_t lineSize;

	((void)argc);
	((void)argv);

	while (1)
	{
		printf("%s", sh_prompt);
		if (_getLine(&readLine, &lineSize, stdin) == -1)
		{
			printf("Leave Shell....\n");
			break;
		}

		readLine[strcspn(readLine, "\n")] = '\0';

		_exec(readLine, argv);
	}

	free(readLine);
	return (0);
}
