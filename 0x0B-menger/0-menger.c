#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: var equal to 3^level
 */
void menger(int level)
{
	int n, row, col;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			fill(row, col);
		}
		printf("%c", '\n');
	}
}

/**
 * fill - function that fill when the vars are 1 using MOD
 * @row: int receive
 * @col: int receive
 */
void fill(int row, int col)
{
	char fill = '#';

	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			fill = ' ';
		row = row / 3;
		col = col / 3;
	}
	printf("%c", fill);
}
