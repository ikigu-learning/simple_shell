#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * read_teractive_cmd - handles interactive commands
 * @path: an array of path dirs
 * @buffer: buffer to read the command into
 *
 * Return: Nothing
*/

char *read_teractive_cmd(char *path[], char *buffer)
{
	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	char *cp;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;

		if (bytes_read == -1)
		{
			printf("an error occurred.\n");
			continue; /* This is the EOF condition */
		}

		if (buffer[0] == '\n')
			continue; /* hitting enter restarts the loop */

		if (starts_with("exit", buffer) == 0)
			break;

		parse_command(buffer, path);
	}

	return (cp);
}

/**
 * read_xteractive_cmd - handles non_interactive commands
 * @path: an array of path dirs
 * @buffer: buffer to read the command into
 *
 * Return: Nothing
*/

char *read_xteractive_cmd(char *path[], char *buffer)
{
	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	char *cp;

	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;

		if (bytes_read == -1)
		{
			continue; /* This is the EOF condition */
		}

		if (buffer[0] == '\n')
			continue; /* if the file encounters a linebreak, read next */

		if (starts_with("exit", buffer) == 0)
			break;

		parse_command(buffer, path);
	}
	return (cp);
}

