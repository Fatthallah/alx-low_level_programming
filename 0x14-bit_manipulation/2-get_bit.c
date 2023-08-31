#include "main.h"

/**
 * get_bit - Index Is BIT
 * @n: The Number The Prog. Will Analys.
 * @index: To Get The Bit
 *
 * Return: The Result
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int X = sizeof(n) * 8;

	if (index >= X)
		return (-1);
	return (n >> index & 1);
}
