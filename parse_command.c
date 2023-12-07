#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * parse_command - executes a shell command
 * @buffer: a buffer containing strings input to the command line
 * @path_tokens: an array of path dirs
 *
 * Return: Nothing
*/

void parse_command(char *buffer, char **path_tokens)
{
	char **command_tokens, *path_to_exe;
	struct stat buf;

	command_tokens = tokenize_command(buffer);

	if (!command_tokens)
		exit(98); /* replace with appropriate command */

	/* Where entered command is NOT an absolute path to an exe... */
	if (stat(command_tokens[0], &buf) != 0)
	{
		/* For each PATH dir, check for the executable file */
		path_to_exe = find_exe(path_tokens, command_tokens[0]);

		if (!path_to_exe) /* if executable isn't found */
		{
			perror("Error");
			exit(98); /* replace with appropriate error and exit */
		}

		/* alloc more mem to hold full path to an exe */
		command_tokens[0] = realloc(command_tokens[0], (_strlen(path_to_exe) + 1));

		if (!command_tokens[0]) /* Handle realloc error */
		{
			perror("Error");
			exit(98); /* print appropriate error and exit */
		}

		_strcpy(command_tokens[0], path_to_exe); /*cp full path to 1st token*/

		free(path_to_exe);
	}

	/* if 1st token is an abs PATH, runs the cmd || run cmd after finding exe*/
	execute_command(command_tokens);
}

