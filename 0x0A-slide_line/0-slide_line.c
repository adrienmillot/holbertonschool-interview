#include "slide_line.h"

/**
 * swap_zeros - Swaps the zeros of an array of integers
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 * @direction: Direction of the slide
 */
void swap_zeros(int *line, int size, int direction)
{
	if (line == NULL || size < 1)
		return;
	if (direction == SLIDE_LEFT)
	{
		if (line[0] == 0)
		{
			int j = 1;

			while (j < size)
			{
				if (line[j] != 0)
				{
					line[0] = line[j];
					line[j] = 0;
					break;
				}
				j++;
			}
		}
		swap_zeros(line + 1, size - 1, direction);
	}
	else if (direction == SLIDE_RIGHT)
	{
		if (line[size - 1] == 0)
		{
			int j = size - 2;

			while (j >= 0)
			{
				if (line[j] != 0)
				{
					line[size - 1] = line[j];
					line[j] = 0;
					break;
				}
				j--;
			}
		}
		swap_zeros(line, size - 1, direction);
	}
}

/**
 * swap_value - Swaps the value of an array of integers
 *
 * @line: Pointer to the array of integers
 * @index_a: Index of the first element to swap
 * @index_b: Index of the second element to swap
 *
 * Return: 1 if the swap was successful, 0 otherwise
 */
int swap_value(int *line, int index_a, int index_b)
{
	if (line[index_b] != 0 && line[index_b] == line[index_a])
	{
		line[index_a] += line[index_b];
		line[index_b] = 0;

		return (1);
	}

	return (0);
}

/**
 * slide_line - Slides a line of integers to the left or right
 *
 * @line: Pointer to the array of integers to be slided
 * @size: Number of elements in @line
 * @direction: Direction to slide the line
 *
 * Return: Number of elements in @line after sliding
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			unsigned int j = i + 1;

			while (j < size)
			{
				if (swap_value(line, i, j))
					break;
				j++;
			}
		}
		swap_zeros(line, size, direction);
	}
	else
	{
		for (i = size - 1; i > 0; i--)
		{
			int j = i - 1;

			while (j >= 0)
			{
				if (swap_value(line, i, j))
					break;
				j--;
			}
		}
		swap_zeros(line, size, direction);
	}

	return (size);
}
