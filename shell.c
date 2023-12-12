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
		ssize_t bytes_read = 0;
		size_t buffer_size = BUFFER_SIZE;

		while (bytes_read != -1)
		{
			bytes_read = getline(&buffer, &buffer_size, stdin);

			if (bytes_read == -1)
			{
				continue; /* This is the EOF condition */
			}

			if (buffer[0] == '\n')
				continue;

			if (starts_with("exit", buffer) == 0)
				break;

			parse_command(buffer, path_tokens);
		}
	}

	free_grid(path_tokens);
	free(buffer);
	return (0);
}

