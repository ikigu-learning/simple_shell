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
 * execute - executes a command line
 * @command_tokens: an array of strings that are the command
 *
 * Return: Nothing
*/

void execute(char *command_tokens[])
{
	int status;

	pid_t my_child = fork();

	if (my_child == 0)
	{

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
