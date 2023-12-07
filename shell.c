#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * main - entry point to simple_shell program
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings passed as arguments to the program
 * @env: an array environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *env[])
{
	char *path, *buffer, **path_tokens;

	(void)argc;
	(void)argv;

	path = find_path(env);
	path_tokens = tokenize_path(path);
	buffer = NULL;

	if (isatty(STDIN_FILENO) == 1)
	{
		read_interactive_command(path_tokens, buffer);
	}
	else
	{
		/* non-interactive mode - Maxwell's responsibility*/

		printf("Maxwell is working on it.\n");
	}

	free_grid(path_tokens);
	free(buffer);
	return (0);
}

