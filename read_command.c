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
 * trim - handles spaces in input
 * @str: string to check for spaces
 *
 *  Return: new location of pointer
*/

char *trim(char *str)
{
	if (str[0] == ' ')
	{
		while (str[0] == ' ')
			str += 1;
	}

	return (str);
}

/**
 * eof - handles end-of-file condition in shell read loop
 * @eof_flag: flag that indicates end of loop condition
 * @atty: flag that indicates whether command is from terminal
 * @bytes_read: number of bytes read
 *
 * Return: 1 if EOF, else -> returns 0
 *
 * Description: When eof_flag is set to 1, shell read loop will terminate.
*/

int eof(int *eof_flag, int atty, int bytes_read)
{
	if (atty != 1 && bytes_read == -1)
	{
		*eof_flag = 1;
	}
	else if (atty == 1 && bytes_read == -1)
	{
		return (1);
	}
	else if (bytes_read != -1)
	{
		return (0);
	}

	return (1);
}

/**
 * read_cmd - reads and handles command lines
 * @arg1: program name
 * @path: an array of path dirs
 * @env: an array of env variables
 * @atty: flag to let us know whether STDIN is a terminal
 *
 * Return: copy of command line buffer to free
*/

char *read_cmd(char *arg1, char *path[], char *env[], int atty)
{
	char *copy_of_input_to_free, *copy_of_input_to_trim, *buffer;

	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	int eof_flag = 0;
	int runs = 0;

	buffer = NULL;

	while (eof_flag != 1)
	{
		if (atty == 1)
			printf("$ ");

		runs++;

		bytes_read = getline(&buffer, &buffer_size, stdin);

		copy_of_input_to_free = buffer;
		copy_of_input_to_trim = buffer;

		copy_of_input_to_trim = trim(copy_of_input_to_trim);

		if (eof(&eof_flag, atty, bytes_read) == 1 ||
		 copy_of_input_to_trim[0] == '\n')
			continue;

		if (starts_with("exit", copy_of_input_to_trim) == 0)
			break;

		if (starts_with("env", copy_of_input_to_trim) == 0)
		{
			print_env(env);
			continue;
		}
		parse_command(arg1, copy_of_input_to_trim, path, runs);
	}

	return (copy_of_input_to_free);
}
