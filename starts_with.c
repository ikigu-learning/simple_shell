#include "main.h"

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
