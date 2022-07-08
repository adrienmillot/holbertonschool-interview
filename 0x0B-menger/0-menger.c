#include "menger.h"

/**
 * check_content - checks if the cell should be display
 *
 * @prmLimit: the level of the cell
 * @prmRow: the row of the cell
 * @prmColumn: the column of the cell
 *
 * Return: 1 if the cell should be displayed, 0 otherwise
 */
int check_content(int prmLimit, int prmRow, int prmColumn)
{
	int divisor, is_display = 1, row_remain, column_remain;

	for (divisor = 1; divisor < prmLimit; divisor *= 3)
	{
		row_remain = (prmRow / divisor) % 3 == 1;
		column_remain = (prmColumn / divisor) % 3 == 1;

		if (row_remain && column_remain && is_display)
			is_display = 0;
	}

	return (is_display);
}

/**
 * menger - Prints a menger triangle of a given level
 *
 * @level: Level of the menger triangle
 *
 * Return: Nothing
 */
void menger(int level)
{
	int column, limit, row;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	limit = pow(3.0, (double) level);

	for (row = 0; row < limit; row++)
	{
		for (column = 0; column < limit; column++)
		{
			if (check_content(limit, row, column) == 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
