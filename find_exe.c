#include "main.h"
#include <sys/stat.h>
#include <stdlib.h>

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
	int size, i, stat_result;
	char *full_path_to_exe, *cat_path;
	struct stat *buf;

	if (!command)
		exit(98);

	while (path_tokens[i])
	{
		size = (_strlen(path_tokens[i]) + _strlen(command) + 1);
		full_path_to_exe = malloc(size);

		if (!full_path_to_exe)
			exit(98);

		cat_path = _strcat(path_tokens[i], command);
		full_path_to_exe = _strcpy(full_path_to_exe, cat_path);

		stat_result = stat(full_path_to_exe, buf);

		if (stat_result == 0)
		{
			return (full_path_to_exe);
		}
	}

	return (NULL);
}
