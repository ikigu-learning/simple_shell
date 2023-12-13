#include "main.h"
#include <stdlib.h>

/**
 * extend_buffer - extends a buffer
 * @i: loop tracker
 * @buffer: array of strings
 * @buffer_size: size of buffer
 *
 * Return: -1 if realloc fails; 1 if realloc succeeds
*/

int extend_buffer(size_t *i, char **buffer, size_t *buffer_size)
{
	if (*i >= *buffer_size)
	{
		*buffer_size *= 2;
		buffer = realloc(buffer, sizeof(char *) * *buffer_size);

		if (!buffer)
		{
			free_grid(buffer);
			return (-1);
		}
	}

	return (1);
}
