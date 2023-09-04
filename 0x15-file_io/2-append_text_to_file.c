#include "main.h"

/**
 * append_text_to_file - make text at end of file.
 * @filename: the name of the file.
 * @text_content: The Added string to the end.
 *
 * Return: Success 1 and fail -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int wr;
	int lt = 0;
	int op;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lt = 0; text_content[lt];)
			lt++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(op, text_content, lt);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
