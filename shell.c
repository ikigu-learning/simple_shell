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
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *path, *buffer, **path_tokens;

	path = find_path(environ);
	path_tokens = tokenize_path(path);
	buffer = NULL;

	if (isatty(STDIN_FILENO) == 1)
	{
		read_interactive_command(path_tokens, buffer);
	}
	else
	{
		read_non_interactive_command(path_tokens, buffer);
	}

	free_grid(path_tokens);
	free(buffer);
	return (0);
}

