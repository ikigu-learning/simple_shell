#include "main.h"

/**
 * _strcpy - copies a string a given string to a given destination
 * @dest: a pointer to where the string will be copied to
 * @src: a pointer to the string to be copied to dest
 *
 * Return: a pointer to dest
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
