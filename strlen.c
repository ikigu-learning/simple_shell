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
