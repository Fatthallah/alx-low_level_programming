#include "main.h"

/**
 * create_file - THis Function Create File.
 * @filename: THe Name of the file that has been created.
 * @text_content: what will be written.
 *
 * Return: -1 if fail or 1 if success.
 */

int create_file(const char *filename, char *text_content)
{
	int wr, lt = 0, fd;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lt = 0; text_content[lt];)
			lt++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fd, text_content, lt);

	if (fd == -1 || wr == -1)
		return (-1);

	close(fd);

	return (1);
}
