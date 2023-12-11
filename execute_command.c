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
 * execute_command - executes a command line
 * @command_tokens: an array of strings that are the command
 *
 * Return: Nothing
*/

void execute_command(char *command_tokens[])
{
	int status;

	pid_t my_child = fork(); /* Create a child process */

	if (my_child == 0)
	{
		/* Run the user-entered command in child process */
		if (execve(command_tokens[0], command_tokens, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(&status);
		/* free here? */
		free_grid(command_tokens);
	}
}
