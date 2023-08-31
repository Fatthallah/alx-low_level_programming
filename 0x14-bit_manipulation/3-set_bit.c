#include "main.h"

/**
 * set_bit - This Function Sets a Bit at a Certin Index.
 * @n: Convert the number to index.
 * @index: Convert an Bit to SET.
 *
 * Return: RETURN 1 IF IT SUCCEED, -1 IF it FAILED.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int X = sizeof(n) * 8;

	if (index >= X)
		return (-1);
	return (!!(*n |= 1L << index));
}
