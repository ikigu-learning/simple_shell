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
	char **buffer, *token;
	size_t i, buffer_size;

	buffer_size = 1024;
	buffer = malloc(sizeof(char *) * buffer_size);

	if (!buffer)
		return (NULL);

	i = 0;

	while (str[i] != '\n')
	{
		i++;
	}

	str[i] = '\0'; /* replaces \n at end of entered cmd line with \0 */

	token = strtok(str, " ");

	i = 0;

	while (token)
	{
		size_t token_len = _strlen(token) + 1;
		
		if (i >= buffer_size)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, sizeof(char *) * buffer_size);

			if (!buffer)
			{
				free(buffer);
				return (NULL);
			}
		}
		
		buffer[i] = malloc(token_len);

		if (buffer[i])
		{
			free_grid(buffer);
			return (NULL);
		}

		_strcpy(buffer[i], token);
		
		i++;
		token = strtok(NULL, " ");
	}

	buffer[i] = NULL;
	return (buffer);
}
