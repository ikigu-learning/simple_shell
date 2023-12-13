#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * tokenize_path - tokenizes a string
 * @str: pointer to string that needs tokenizing
 *
 * Return: an array of string pointers
*/

char **tokenize_path(char *str)
{
	char **buffer, *token;
	size_t i, buffer_size;	

	i = 0;
	buffer_size = BUFFER_SIZE;
	buffer = malloc(sizeof(char *) * buffer_size);

	if (!buffer)
		return (NULL);

	str += 5;
	token = strtok(str, ":");

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
		token = strtok(NULL, ":");
	}

	buffer[i] = NULL;
	return (buffer);
}
