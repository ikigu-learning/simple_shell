#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * parse_command - executes a shell command
 * @buffer: a buffer containing strings input to the command line
 * @path_tokens: an array of path dirs
 * @argv: the name of the program
 *
 * Return: Nothing
*/

void parse_command(char *buffer, char **path_tokens, char *argv)
{
	char **command_tokens, *path_to_exe;


	command_tokens = tokenize_command(buffer);

	if (!command_tokens)
		exit(98); /* replace with appropriate command */

	/* Where entered command is NOT an absolute path to an exe... */
	if (_isin(command_tokens[0], '/'))
	{
		execute_command(command_tokens);
		return;
	}
	else
	{
	
		/* For each PATH dir, check for the executable file */
		path_to_exe = find_exe(path_tokens, command_tokens[0]);

		if (!path_to_exe) /* if executable isn't found */
		{
			_notfound(argv, command_tokens[0]);
			return;
		}

		/* alloc more mem to hold full path to an exe */
		command_tokens[0] = realloc(command_tokens[0], (_strlen(path_to_exe) + 1));

		if (!command_tokens[0]) /* Handle realloc error */
		{
			perror("Error");
			return;
		}

		_strcpy(command_tokens[0], path_to_exe); /*cp full path to 1st token*/

		free(path_to_exe);
	}

	/* if 1st token is an abs PATH, runs the cmd/runs cmd after finding exe */
	execute_command(command_tokens);
}
/**
 * _notfound - a function to print not found error
 * @argv: the name of the function
 * @com: the command not found
 */
void _notfound(char *argv, char *com)
{
	size_t ind;
	char *nt, *delim;

	nt = "not found";
	delim = ": ";
	for (ind = 0; argv[ind] != '\0'; ind++)
	{
		_putchar(argv[ind]);
	}
	for (ind = 0; delim[ind] != '\0'; ind++)
	{
		_putchar(delim[ind]);
	}
	_putchar('1');
	for (ind = 0; delim[ind] != '\0'; ind++)
	{
		_putchar(delim[ind]);
	}
	for (ind = 0; com[ind] != '\0'; ind++)
	{
		_putchar(com[ind]);
	}
		for (ind = 0; delim[ind] != '\0'; ind++)
	{
		_putchar(delim[ind]);
	}
	for (ind = 0; nt[ind] != '\0'; ind++)
	{
		_putchar(nt[ind]);
	}
	_putchar('\n');
}

int _isin(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}