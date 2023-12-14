#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_env - prints the environment
 * @env: environment
 *
 * Return: Nothing
*/

void print_env(char *env[])
{
	int i, j;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j]; j++)
		{
			_putchar(env[i][j]);
		}

		_putchar('\n');
	}
}

/**
 * handle_spaces - handles spaces in input
 * @str: string to check for spaces
 *
 *  Return: new location of pointer
*/

char *handle_spaces(char *str)
{
	if (str[0] == ' ')
	{
		while (str[0] == ' ')
			str += 1;

	}

	return (str);
}

/**
 * read_teractive_cmd - handles interactive commands
 * @path: an array of path dirs
 * @buffer: buffer to read the command into
 * @env: environment
 *
 * Return: Nothing
*/

char *read_teractive_cmd(char *path[], char *buffer, char *env[])
{
	char *cp, *cp_for_spaces;

	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;
		cp_for_spaces = buffer;

		cp_for_spaces = handle_spaces(cp_for_spaces);

		if (bytes_read == -1)
		{
			printf("an error occurred.\n");
			continue; /* This is the EOF condition */
		}

		if (cp_for_spaces[0] == '\n')
			continue; /* hitting enter restarts the loop */

		if (starts_with("exit", cp_for_spaces) == 0)
			break;

		if (starts_with("env", cp_for_spaces) == 0)
		{
			print_env(env);
			continue;
		}

		parse_command(cp_for_spaces, path);
	}

	return (cp);
}

/**
 * read_xteractive_cmd - handles non_interactive commands
 * @path: an array of path dirs
 * @buffer: buffer to read the command into
 * @env: environment
 *
 * Return: Nothing
*/

char *read_xteractive_cmd(char *path[], char *buffer, char *env[])
{
	char *cp, *cp_for_spaces;

	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;

	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;
		cp_for_spaces = buffer;
		cp_for_spaces = handle_spaces(cp_for_spaces);

		if (bytes_read == -1)
		{
			continue; /* This is the EOF condition */
		}

		if (cp_for_spaces[0] == '\n')
			continue; /* if the file encounters a linebreak, read next */

		if (starts_with("exit", cp_for_spaces) == 0)
			break;

		if (starts_with("env", cp_for_spaces) == 0)
		{
			print_env(env);
			break;
		}

		parse_command(cp_for_spaces, path);
	}
	return (cp);
}

