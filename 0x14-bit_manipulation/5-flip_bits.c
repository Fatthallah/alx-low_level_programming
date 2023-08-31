#include "main.h"

/**
 * flip_bits - This FUNCTION FLIPS THE BITS.
 * @n: 1st Number.
 * @m: 2nd Number.
 *
 * Return: Number Of Bits.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int XX = n ^ m;
	unsigned int X = 0;

	while (XX)
	{
		if (XX & 1ul)
			X++;
		XX = XX >> 1;
	}
	return (X);
}
