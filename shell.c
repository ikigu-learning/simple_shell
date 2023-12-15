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
 * @env: the environment
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *env[])
{
	char *path, *buffer, **path_tokens, *cp, *path_copy;
	int path_length;

	(void)argv;

	if (argc != 1)
	{
		exit(0);
	}

	path = find_path(environ);
	path_length = _strlen(path) + 1;
	path_copy = malloc(path_length);

	if (!path_copy)
		return (1);
	_strcpy(path_copy, path);
	path_tokens = tokenize(path_copy, ":");
	buffer = NULL;

	if (isatty(STDIN_FILENO) == 1)
	{
		cp = read_cmd(path_tokens, buffer, env, 1);
	}
	else
	{
		cp = read_cmd(path_tokens, buffer, env, 0);
	}

	free(path_copy);
	free_grid(path_tokens);
	free(cp);
	return (0);
}

