#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * run_command - executes a shell command
 * @env: the process' environment
 * @buffer: a buffer containing strings input to the command line
 *
 * Return: Nothing
*/

void run_command(char **env, char *buffer)
{
	char **command_tokens, **path_tokens, *path, *path_to_exe;
	struct stat buf;

	path = find_path(env);
	path_tokens = tokenize_path(path);
	command_tokens = tokenize_command(buffer);

	if (stat(command_tokens[0], &buf) != 0)
	{
		path_to_exe = find_exe(path_tokens, command_tokens[0]);

		if (!path_to_exe)
		{
			perror("Error");
			exit(98); /* print appropriate error and exit */
		}

		command_tokens[0] = realloc(command_tokens[0], (_strlen(path_to_exe) + 1));

		if (!command_tokens[0])
		{
			perror("Error");
			exit(98); /* print appropriate error and exit */
		}

		_strcpy(command_tokens[0], path_to_exe);

		free(path_to_exe);
		free_grid(path_tokens);
		free(buffer);
	}

	execute(command_tokens);
}

