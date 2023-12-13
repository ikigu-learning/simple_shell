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
	ssize_t bytes_read = 0;
	int i;
	size_t buffer_size = BUFFER_SIZE;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &buffer_size, stdin);

		if (bytes_read == -1)
		{
			printf("an error occurred.\n");
			continue; /* This is the EOF condition */
		}

		for (i = 0; buffer[i] == ' '; i = 0)
			buffer += 1; /* Added to trim */

		if (buffer[0] == '\n')
			continue;

		if (starts_with("exit", buffer) == 0)
			break;

		parse_command(buffer, path_tokens);
	}
}

/**
 * read_non_interactive_command - handles non_interactive commands
 * @path_tokens: an array of path dirs
 * @buffer: buffer to read the command into
 *
 * Return: Nothing
*/

void read_non_interactive_command(char *path_tokens[], char *buffer)
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
