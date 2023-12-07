#include <stdlib.h>

/**
 * _strlen - a function that counts the length of a string
 * @str: the string to get the length of
 *
 * Return: the length of the string
*/

int _strlen(char *str)
{
	int count = 0;

	while (str[count])
	{
		count++;
	}

	return (count);
}


/**
  * starts_with - checks whether str2 starts with str1
  * @str1: the string to compare against
  * @str2: the string to compare
  *
  * Return: equal ? 0 : the difference
  */

int starts_with(char *str1, char *str2)
{
	int n = 0;
	int length = _strlen(str1);

	if (!str1 || !str2 || length == 0)
		return (-1);

	while (length > n)
	{
		if (str1[n] != str2[n])
		{
			return (str1[n] - str2[n]);
		}

		n++;
	}

	return (0);
}

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

/**
 * _strcat - concatenates two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: a pointer to the new string on success,
 * NULL on failure
*/

char *_strcat(char *str1, char *str2)
{
	int size;
	char *new_string;

	if (!str1 || !str2)
		return (NULL);

	size = _strlen(str1) + _strlen(str2) + 1;
	new_string = malloc(size);

	if (!new_string)
		return (NULL);

	_strcpy(new_string, str1);
	_strcpy((new_string + _strlen(str1)), str2);

	return (new_string);
}


/**
 * replace_newline_char_with_null - replaces a cmd line newline char
 * @str: the string to amend
 *
 * Return: Nothing
*/

void replace_newline_char_with_null(char *str)
{
	int i = 0;

	while (str[i] != '\n')
	{
		i++;
	}

	str[i] = '\0';
}
