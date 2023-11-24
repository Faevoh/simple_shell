#include "main.h"
/**
 * cmd_cd - change directory
 * @path: path to change to
 * Return: 0 if successful, 1 if not
 */
void cmd_cd(char *path)
{
	char *home = getenv("HOME");
	char *oldpwd = getenv("OLDPWD");
	char *pwd = getenv("PWD");
	char cwd[1024];

	if (!path)
	{
		if (chdir(home) == -1)
		{
			perror("cd");
			return;
		}
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", home, 1);
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd)
		{
			if (chdir(oldpwd) == -1)
			{
				perror("cd");
				return;
			}
			setenv("OLDPWD", pwd, 1);
			setenv("PWD", oldpwd, 1);
		}
		else
		{
			fprintf(stderr, "No previous working directory\n");
		}
	}
	else
	{
		if (chdir(path) == -1)
		{
			perror("cd");
			return;
		}
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", cwd, 1);
	}
}
