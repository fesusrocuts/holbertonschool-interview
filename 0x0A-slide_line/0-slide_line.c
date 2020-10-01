#include "slide_line.h"
int walk_right(int *line, int size);
int walk_left(int *line, int size);
void join_right(int *line, size_t size);
void join_left(int *line, size_t size);

/**
 * join_left - merge numbers to left
 * @line: array
 * @size: size
 */
void join_left(int *line, size_t size)
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
		/* find next non-zero */
		while (next < (int) size && line[next] == 0)
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
 * join_right - merge numbers to right
 * @size: size
 * @line: array
 */
void join_right(int *line, size_t size)
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
		/* find next non-zero */
		while (next >= 0 && line[next] == 0)
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
 * walk_left - move numbers to left
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int walk_left(int *line, int size)
{
	int current, next;

	for (current = 0, next = 1; current < size; current++)
	{
		if (line[current])
		{
			next++;
			continue;
		}
		/* find next number to move */
		while (next < size && line[next] == 0)
			next++;
		/* no more number to move */
		if (next >= size)
			return (1);
		line[current] = line[next];
		if (current != next)
			line[next] = 0;
	}
	return (1);
}
/**
 * walk_right - move numbers to right
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int walk_right(int *line, int size)
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
	if ((direction != SLIDE_RIGHT && direction != SLIDE_LEFT) || !line)
		return (0);
	if (direction == SLIDE_LEFT)
		join_left(line, size);
	else
		join_right(line, size);
	return (direction == SLIDE_LEFT ?
		walk_left(line, size) : walk_right(line, size));
}
