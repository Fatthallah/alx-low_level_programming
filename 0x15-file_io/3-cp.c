#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void cl_fl(int f);
char *cr_bf(char *fl);

/**
 * 1st Documentation.
 * cr_bf BuFFER 1024 .
 * @fl: The Files Name.
 *
 * Return: The BUFFER.
 */

char *cr_bf(char *fl)
{
	char *bf;

	bf = malloc(sizeof(char) * 1024);

	if (bf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fl);
		exit(99);
	}

	return (bf);
}

/**
 * 2nd Documentation.
 * cl_fl - CLOSE THE FILE.
 * @f: THE FILE.
 */

void cl_fl(int f)
{
	int cc;

	cc = close(f);

	if (cc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close f %d\n", f);
		exit(100);
	}
}

/**
 * 3rd Cocumentation
 * main - The Copy.
 * @agc: No. Of Arg.
 * @agv: The Array.
 *
 * Return: 0 on success.
 *
 * If count - 97.
 * If not exist  - 98.
 * If cannot be created - 99.
 * If cannot be closed - 100.
 */

int main(int agc, char *agv[])
{
	int too;
	int rrr;
	int www;
	int frm;
	char *bf;

	if (agc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bf = cr_bf(agv[2]);
	frm = open(agv[1], O_RDONLY);
	rrr = read(frm, bf, 1024);
	too = open(agv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || rrr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", agv[1]);
			free(bf);
			exit(98);
		}

		www = write(too, bf, rrr);
		if (too == -1 || www == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", agv[2]);
			free(bf);
			exit(99);
		}

		rrr = read(frm, bf, 1024);
		too = open(agv[2], O_WRONLY | O_APPEND);

	} while (rrr > 0);

	free(bf);
	cl_fl(frm);
	cl_fl(too);

	return (0);
}
