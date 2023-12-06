#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * parse_command - executes a shell command
 * @env: the process' environment
 * @buffer: a buffer containing strings input to the command line
 *
 * Return: Nothing
*/

void parse_command(char **env, char *buffer)
{
	char **command_tokens, **path_tokens, *path, *path_to_exe;
	struct stat buf;

	/* Find the PATH from env, tokenize it, also tokenize user-entered command */
	path = find_path(env);
	printf("PATH->%s\n", path);
	path_tokens = tokenize_path(path);
	command_tokens = tokenize_command(buffer);

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
		free(buffer);
	}

	/* if 1st token is an abs PATH, runs the cmd || run cmd after finding exe*/
	execute(command_tokens, path_tokens);
}

