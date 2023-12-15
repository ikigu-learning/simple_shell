#include "main.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * find_exe - finds an executable file in $PATH
 * @path_tokens: an array of the dirs in path
 * @command: the first string user entered in a command line
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

	if (stat(command, &buf) == 0) /* if command is already an executable */
		return (command);

	for (i = 0; path_tokens[i]; i++)
	{
		/*Calc the length of the concatenated path and alloc memory for it*/
		size = _strlen(path_tokens[i]) + _strlen(command) + 2;
		full_path_to_exe = malloc(size);

		/* handle malloc error */
		if (!full_path_to_exe)
			return (NULL);

		/* Concatenate first str of user-entered cmd and current PATH token */
		_strcpy(full_path_to_exe, path_tokens[i]);
		_strcpy((full_path_to_exe + _strlen(full_path_to_exe)), "/");
		_strcpy((full_path_to_exe + _strlen(full_path_to_exe)), command);

		/* Return the full, concatenated path to the executable file if found*/
		if (stat(full_path_to_exe, &buf) == 0)
			return (full_path_to_exe);

		free(full_path_to_exe); /* to avoid reallocating in the next iteration */
	}

	return (NULL); /* if an executable file wasn't found */
}
