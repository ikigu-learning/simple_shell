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

	i = 0;
	buffer_size = BUFFER_SIZE;
	buffer = malloc(sizeof(char *) * buffer_size);

	if (!buffer)
		return (NULL);

	replace_newline_char_with_null(str);
	token = strtok(str, " ");

	while (token)
	{
		size_t token_len = _strlen(token) + 1;
		
		if (i >= buffer_size)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, sizeof(char *) * buffer_size);

			if (!buffer)
			{
				free_grid(buffer);
				return (NULL);
			}
		}
		
		buffer[i] = malloc(token_len);

		if (!buffer[i])
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
