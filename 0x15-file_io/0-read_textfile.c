#include <stdlib.h>
#include "main.h"

/**
 * read_textfile- This Fun. will read the text file and print it to STDOUT.
 * @filename: Name of the file that is beeing read.
 * @letters: The number of the Letters the program will read.
 * Return: r- the number of the bytes that has been read and printed.
 * 0 if fail
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t wr;
	char *b;
	ssize_t f;
	ssize_t t;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	t = read(f, b, letters);
	wr = write(STDOUT_FILENO, b, t);

	free(b);
	close(f);
	return (wr);
}

