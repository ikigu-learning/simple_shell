#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
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
	ssize_t bytes_read;
	char *path, **path_tokens;

	char *buffer = NULL;
	size_t size = 1024;

	(void)argc;
	(void)argv;

	path = find_path(env);
	path_tokens = tokenize_path(path);

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{	
			printf("$ ");
			bytes_read = getline(&buffer, &size, __stdinp);

			if (bytes_read == -1)
			{	
				printf("an error occurred.\n");
				continue;
			}

			if (buffer[0] == '\n')
				continue;

			if (starts_with("exit", buffer) == 0)
				break;

			parse_command(buffer, path_tokens);
		}
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

