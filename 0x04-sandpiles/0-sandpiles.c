#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 *
 * @prmGrid: 3x3 grid
 *
 * Return: void
 */
void print_grid(int prmGrid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (column)
				printf(" ");
			printf("%d", prmGrid[row][column]);
		}
		printf("\n");
	}
}

/**
 * checkGrid - Check if grid is stable
 *
 * @prmGrid: 3x3 grid
 *
 * Return: 1 if stable, 0 if not
 */
int checkGrid(int prmGrid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (prmGrid[row][column] > 3)
				return (0);
		}
	}

	return (1);
}

/**
 * sumGrid - Sum two 3x3 grids
 *
 * @srcGrid: 3x3 grid
 * @destGrid: 3x3 grid
 *
 * Return: void
 */
void sumGrid(int srcGrid[3][3], int destGrid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			destGrid[row][column] += srcGrid[row][column];
			srcGrid[row][column] = 0;
		}
	}
}

/**
 * transmitGrain - Transmit grains from grid to adjacent grid
 *
 * @prmGrid: 3x3 grid
 * @prmRow: Row of grid
 * @prmColumn: Column of grid
 *
 * Return: void
 */
void transmitGrain(int prmGrid[3][3], int prmRow, int prmColumn)
{
	prmGrid[prmRow][prmColumn] -= 4;

	if (prmRow - 1 >= 0)
		prmGrid[prmRow - 1][prmColumn]++;
	if (prmRow + 1 < 3)
		prmGrid[prmRow + 1][prmColumn]++;
	if (prmColumn - 1 >= 0)
		prmGrid[prmRow][prmColumn - 1]++;
	if (prmColumn + 1 < 3)
		prmGrid[prmRow][prmColumn + 1]++;
}

/**
 * sandpiles_sum - Print 3x3 grids sum
 *
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column, status1 = 0, status2 = 0;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			if (grid1[row][column] > 0 && status1 == 0)
				status1 = 1;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			if (grid1[row][column] > 0 && status1 == 0)
				status1 = 1;

	do {

		for (row = 0; row < 3; row++)
			for (column = 0; column < 3; column++)
				if (grid2[row][column] > 0 && status2 == 0)
					status2 = 1;

		sumGrid(grid2, grid1);
		if (status1 == 0 || status2 == 0)
			return;

		printf("=\n");
		print_grid(grid1);

		for (row = 0; row < 3; row++)
			for (column = 0; column < 3; column++)
				if (grid1[row][column] > 3)
					transmitGrain(grid2, row, column);

		sumGrid(grid2, grid1);
	} while (!checkGrid(grid1));
}
