#include "slide_line.h"
int move_right(int *line, int size);
int move_left(int *line, int size);
void merge_right(int *line, size_t size);
void merge_left(int *line, size_t size);
/**
 * merge_left - merge numbers to left
 * @line: array
 * @size: size
 */
void merge_left(int *line, size_t size)
{
	int i, next;

	for (i = 0, next = 1; next < (int) size;)
	{
		if (!line[i])
		{
			i++;
			next++;
			continue;
		}
		while (next < (int) size && line[next] == 0) /* find next non-zero */
			next++;
		if (next >= (int) size)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next + 1;
			next = i + 1;
		}
		else
		{
			i = next;
			next = i + 1;
		}
	}
}

/**
 * merge_right - merge numbers to right
 * @size: size
 * @line: array
 */
void merge_right(int *line, size_t size)
{
	int i, next;

	for (i = (int) size - 1, next = i - 1; next >= 0;)
	{
		if (!line[i])
		{
			i--;
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0) /* find next non-zero */
			next--;
		if (next < 0)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next - 1;
			next = i - 1;
		}
		else
		{
			i = next;
			next--;
		}
	}
}
/**
 * move_left - move numbers to left
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int move_left(int *line, int size)
{
	int current, next;

	for (current = 0, next = 1; current < size; current++)
	{
		if (line[current])
		{
			next++;
			continue;
		}
		while (next < size && line[next] == 0) /* find next number to move */
			next++;
		if (next >= size) /* no more number to move */
			return (1);
		line[current] = line[next];
		if (current != next)
			line[next] = 0;
	}
	return (1);
}
/**
 * move_right - move numbers to right
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int move_right(int *line, int size)
{
	int current, next;

	for (current = size - 1, next = current - 1; current >= 0; current--)
	{
		if (line[current])
		{
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0) /* find next number to move */
			next--;
		if (next < 0) /* no more number to move */
			return (1);
		line[current] = line[next];
		if (current != next)
			line[next] = 0;
	}
	return (1);
}
/**
 * slide_line - slide array of integers to the left or right
 * @line: array
 * @size: size of array
 * @direction: direction to slide
 *
 * Return: 1 for success, 0 for failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT && direction != SLIDE_RIGHT) || !line)
		return (0);
	if (direction == SLIDE_LEFT)
		merge_left(line, size);
	else
		merge_right(line, size);
	return (direction == SLIDE_LEFT ?
		move_left(line, size) : move_right(line, size));
}
