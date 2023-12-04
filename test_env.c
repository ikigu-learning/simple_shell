#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - tests the path_tokenization function
 * @argc: number of args passed to the program
 * @argv: an array of strings passed as arguments to the program
 * @env: an array of environment variables
 *
 * Return: Always 0
*/

int main(int argc, char *argv[], char *env[])
{
	char *path, **path_tokens;
	int i;

	(void)argc;
	(void)argv;

	path = find_path(env);

	if (!path)
		printf("path not found\n");

	path_tokens = tokenize_path(path);

	if (!path_tokens)
		exit(98);

	printf("%s\n", path_tokens[3]);

	i = 0;

	while (path_tokens[i])
	{
		free(path_tokens[i]);
		i++;
	}

	free(path_tokens);

	return (0);
}
