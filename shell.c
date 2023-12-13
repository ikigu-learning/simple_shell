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
		ssize_t bytes_read = 0;
		int i = 0;
		size_t buffer_size = BUFFER_SIZE;

		while (bytes_read != -1)
		{
			bytes_read = getline(&buffer, &buffer_size, stdin);

			if (bytes_read == -1)
			{
				continue; /* This is the EOF condition */
			}

			for (i = 0; buffer[i] != ' '; i = 0)
				buffer += 1;

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

