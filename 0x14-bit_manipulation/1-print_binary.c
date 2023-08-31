#include "main.h"

/**
 * print_binary: Prints The Binary Number that is equal to Decimal Number.
 * @n: Number to Be Printed In Binary After Convertion.
 */
void print_binary(unsigned long int n)
{
	int X = sizeof(n) * 8;
	int P = 0;

	while (X)
	{
		if (n & 1L << --X)
		{
			_putchar('1');
			P++;
		}
		else if (P)
			_putchar('0');
	}
	if (!P)
		_putchar('0');
}
