#include "main.h"
/**
 * custom_getline- function that uses a buffer to read many chars at once
 * and call the least possible the read system call
 * @ps: parameter struct
 * @pb: pointer to buffer pointer
 * @len: size of pointer to buffer
 * Return: user input
 */
int custom_getline(info_t *ps, char **pb, size_t *len)
{
	static char buffer[READ_BUFFER_SIZE];
	static size_t x, l;
	size_t y;
	ssize_t b = 0;
	char *p = NULL, *p2 = NULL, *d;
	(void) ps;

	p = *pb;
	if (p && len)
	{
		b = *len;
	}
	if (x == l)
	{
		x = l = 0;
	}
	d = strchr(buffer + x, '\n');
	y = d ? 1 + (unsigned int)(d - buffer) : l;
	p2 = _realloc(p, b, b ? b + y : y + 1);
	if (!p2)
	{
		return (p ? free(p), -1 : -1);
	}
	if (b)
	{
		strncat(p2, buffer + x, y - x);
	}
	else
	{
		strncpy(p2, buffer + x, y - x + 1);
	}
	b += y - x;
	x = y;
	p = p2;
	if (len)
	{
		*len =  b;
	}
	*pb = p;
	return (b);
}




