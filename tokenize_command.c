#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * tokenize_command - tokenizes a command line
 * @str: pointer to string that needs tokenizing
 *
 * Return: an array of string pointers
*/

char **tokenize_command(char *str)
{
	char **buffer, *token, *new_string;
	int i;

	buffer = malloc(sizeof(char *) * 1024);

	if (!buffer)
		return (NULL);

	i = 0;

	while (str[i] != '\n')
	{
		i++;
	}

	str[i] = '\0'; /* replaces new line character with a NULL char */

	token = strtok(str, " ");

	i = 0;

	while (token)
	{
		new_string = malloc(_strlen(token) + 1);

		if (!new_string)
		{
			free(buffer);
			return (NULL);
		}

		_strcpy(new_string, token);
		buffer[i] = new_string;
		i++;
		token = strtok(NULL, " ");
	}

	buffer[i] = NULL;
	return (buffer);
}
