#include "main.h"
#include <sys/types.h>
#include <stdio.h>


/**
 * read_interactive_command - handles interactive commands
 * @path_tokens: an array of path dirs
 * @buffer: buffer to read the command into
 *
 * Return: Nothing
*/

void read_interactive_command(char *path_tokens[], char *buffer)
{
	ssize_t bytes_read;

	size_t buffer_size = BUFFER_SIZE;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &buffer_size, __stdinp);

		if (bytes_read == -1)
		{
			printf("an error occurred.\n");
			continue; /* This is the EOF condition */
		}

		if (buffer[0] == '\n')
			continue;

		if (starts_with("exit", buffer) == 0)
			break;

		parse_command(buffer, path_tokens);
	}
}

