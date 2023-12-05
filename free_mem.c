#include <stdlib.h>

/**
 * free_grid - frees a grid
 * @grid: grid to free
 *
 * Return: Nothing
*/

void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}

	free(grid);
}
