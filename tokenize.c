#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * prep - prepares a string for tokenization
 * @str: the string to prepare for tokenization
 *
 * Return: the new string
 *
 * Description: For a command line, the newline character at the end
 * is replaced with a null character. For PATH, the 'PATH=' part is removed.
*/

char *prep(char *str)
{
	if (starts_with("PATH=", str) == 0)
	{
		str += 5;
	}
	else
	{
		replace_newline_char_with_null(str);
	}

	return (str);
}


/**
 * tokenize - tokenizes a string
 * @str: pointer to string that needs tokenizing
 * @delim: the delimiter
 *
 * Return: an array of string pointers
*/

char **tokenize(char *str, char *delim)
{
	char **buffer, *token;
	size_t i, buffer_size;

	if (!str)
		return (NULL);

	i = 0;
	buffer_size = BUFFER_SIZE;
	buffer = malloc(sizeof(char *) * buffer_size);

	if (!buffer)
		return (NULL);

	str = prep(str);
	token = strtok(str, delim);

	while (token)
	{
		size_t token_len = _strlen(token) + 1;

		if (extend_buffer(&i, buffer, &buffer_size) == -1)
		return (NULL);

		buffer[i] = malloc(token_len);

		if (!buffer[i])
		{
			free_grid(buffer);
			return (NULL);
		}

		_strcpy(buffer[i], token);
		i++;
		token = strtok(NULL, delim);
	}

	buffer[i] = NULL;
	return (buffer);
}
