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

/**
 * _isin - checks whether character c is present in strinc s
 * @c: character to check whether is included
 * @s: string to check agains
 *
 * Return: 1 or 0
*/

int _isin(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}
