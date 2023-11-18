#include "main.h"

/**
 * _1exit - exit with a status code
 * @status: status code to exit with
 * @c: count of command
 * @a: name of shell
 * @ag: string of input command
 *
 * Return: exit code
 */
int ex_code;

int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag)
{
	int i = ex_code;
	int j = 0;

	if (status != NULL)
	{
		while (status[j] != '\0')
		{
			if (!(status[j] > 47 && status[j] < 58))
			{
				_perrore(a, c, ag[0], ag[1]);
				ex_code = 2;
				return (500);
			}
			j++;
		}
		i = _atoi(status);
	}

	return (i);
}
