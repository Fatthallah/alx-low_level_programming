#include "main.h"

/**
 * clear_bit - This Function CLEARS THE BITS.
 * @n: Convert The Number to an INDEX.
 * @index: It Makes The BIT TO BE CLEARED.
 *
 * Return: RETURN 1 IF SUCCEED, -1 IF FAILED.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int X = sizeof(n) * 8;

	if (index >= X)
		return (-1);
	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}
