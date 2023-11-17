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
	char *readLine = NULL;
	size_t lineSize;
	((void)argc);

	while (1)
	{
		printf("%s", sh_prompt);
		if (_getLine(&readLine, &lineSize, stdin) == -1)
		{
			printf("Leave Shell....\n");
			break;
		}
		readLine[_strlen(readLine) - 1] = '\0';
		_exec(readLine, argv);
	}

	free(readLine);
	return (0);
}
