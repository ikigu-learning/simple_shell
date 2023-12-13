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
 * @argc: number of arguments
 * @argv: an array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *path, *buffer, **path_tokens, *cp;

	if (argc != 1)
	{
		exit(98);

	}
	path = find_path(environ);
	path_tokens = tokenize_path(path);
	buffer = NULL;

	if (isatty(STDIN_FILENO) == 1)
	{
		cp = read_interactive_command(path_tokens, buffer, argv[0]);
	}
	else
	{
		cp = read_non_interactive_command(path_tokens, buffer, argv[0]);
	}

	free_grid(path_tokens);
	free(cp);
	return (0);
}

