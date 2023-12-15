#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * handle_cmd_not_found - prints file not found to the stderr
 * @arg1: name of program
 * @runs: number of lines read
 * @command: latest entered command
*/

void handle_cmd_not_found(char *arg1, int runs, char *command)
{
	char buffer[BUFFER_SIZE];
	char number_buffer[8];

	sprintf(number_buffer, "%d", runs);

	_strcpy(buffer, arg1); /* .hsh */
	_strcpy(buffer + _strlen(buffer), ": ");  /* ./hsh:  */
	_strcpy(buffer + _strlen(buffer), number_buffer);  /* .hsh: 1 */
	_strcpy(buffer + _strlen(buffer), ": "); /* ./hsh: 1: */
	_strcpy(buffer + _strlen(buffer), command); /* ./hsh: 1: command */

	perror(buffer);
}

/**
 * parse_command - executes a shell command
 * @arg1: program name
 * @buffer: a buffer containing strings input to the command line
 * @path: an array of path dirs
 * @runs: number of times command has been called
 *
 * Return: Nothing
*/

void parse_command(char *arg1, char *buffer, char **path, int runs)
{
	char **command_tokens, *path_to_exe;

	command_tokens = tokenize(buffer, " ");

	/* Where entered command might be an absolute path to an exe... */
	if (_isin(command_tokens[0], '/') == 1 &&
	find_exe(path, command_tokens[0]) != NULL)
	{
		execute_command(command_tokens);
		return;
	}
	else
	{
		path_to_exe = find_exe(path, command_tokens[0]);

		if (!path_to_exe) /* if executable isn't found */
		{
			handle_cmd_not_found(arg1, runs, command_tokens[0]);
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
