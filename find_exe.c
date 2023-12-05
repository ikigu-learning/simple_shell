#include "main.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * find_exe - finds an executable file in $PATH
 * @path_tokens: an array of the files in path
 * @command: a string that was given as a command line
 *
 * Return: a pointer to the full path of the command;
 * NULL if the command doesn't exist
*/

char *find_exe(char *path_tokens[], char *command)
{
	int i;
	size_t size;
	char *full_path_to_exe;
	struct stat buf;

	char slash[2] = "/";

	if (!command)
		exit(98); /* exit appropriately */

	i = 0;

	while (path_tokens[i])
	{
<<<<<<< HEAD
		size = (_strlen(path_tokens[i]) + _strlen(command) + 1);
=======
		size = _strlen(path_tokens[i]) + _strlen(command) + 2;
>>>>>>> f300c33aba2b689390e1715e6ceaf729dea5499f
		full_path_to_exe = malloc(size);

		if (!full_path_to_exe)
			return (NULL);

		_strcpy(full_path_to_exe, path_tokens[i]);
		_strcpy((full_path_to_exe + _strlen(full_path_to_exe)), slash);
	    _strcpy((full_path_to_exe + _strlen(full_path_to_exe)), command);

		if (stat(full_path_to_exe, &buf) == 0)
		{
			return (full_path_to_exe);
		}

		i++;
		free(full_path_to_exe);
	}

	return (NULL);
}
