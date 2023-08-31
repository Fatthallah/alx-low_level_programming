#include "main.h"

/**
 * binary_to_uint: Converts Binary Number into an UNSIGNED int.
 * @b: The Binary Number in form of STRING.
 *
 * Return: The Number AFTER Convertion.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int Final = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		Final = Final * 2 + (*b++ - '0');
	}

	return (Final);
}

