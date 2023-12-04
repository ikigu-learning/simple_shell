#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_path - finds path in environent variables
 * @env: an array of pointers to env variables
 *
 * Return: pointer to path; NULL if not found
*/

char *find_path(char *env[])
{
	int i = 0;
	char *path = "PATH";

	while (env[i])
	{
		if (starts_with(path, env[i]) == 0)
		{
			return (env[i]);
		}

		i++;
	}

	return (NULL);
}
