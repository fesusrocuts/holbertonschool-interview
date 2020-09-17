#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: is the number to be checked
 * Return: Return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned int bk, fw, reverse[20];
	unsigned long curr;

	for (fw = 0, curr = n; curr != 0; fw++, curr = curr / 10)
	{
		reverse[fw] = curr % 10;
	}
	for (bk = fw - 1, curr = n; bk > fw / 2 - 1; bk--, curr = curr / 10)
	{
		if (reverse[bk] != curr % 10)
		{
			return (0);
		}
	}
	return (1);
}
