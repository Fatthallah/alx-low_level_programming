#include "main.h"

/**
 * get_endianness - Check the System.
 *
 * Return: 0 for BIG, 1 for SMALL.
 */

int get_endianness(void)
{
	unsigned int X = 1;

	return (*(char *)&X);
}
