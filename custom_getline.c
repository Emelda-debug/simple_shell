#include "main.h"
/**
 * read_buffer - reads a buffer
 * @ps: parameter struct
 * @b: buffer
 * @s: size
 * Return: r
 */
ssize_t read_buffer(info_t *ps, char *b, size_t *s)
{
	ssize_t r = 0;

	if (*s)
		return (0);
	r = read(ps->readfd, b, READ_BUFFER_SIZE);
	if (r >= 0)
		*s = r;
	return (r);
}
/**
 * custom_getline - gets the next line of input from STDIN
 * @ps: parameter struct
 * @pnt: address of pointer to buffer, preallocated or NULL
 * @len: size of preallocated buffer if not NULL
 * Return: str
 */
int custom_getline(info_t *ps, char **pnt, size_t *len)
{
	static char buffer[READ_BUFFER_SIZE];
	static size_t i, l;
	size_t k;
	ssize_t r = 0, str = 0;
	char *p = NULL, *p2 = NULL, *c;

	p = *pnt;
	if (p && len)
		str = *len;
	if (i == l)
		i = l = 0;

	r = read_buffer(ps, buffer, &l);
	if (r == -1 || (r == 0 && l == 0))
		return (-1);

	c = strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : l;
	p2 = _realloc(p, str, str ? str + k : k + 1);
	if (p2)
		return (p ? free(p), -1 : -1);

	if (str)
		strncat(p2, buffer + i, k - i);
	else
		strncpy(p2, buffer + i, k - i + 1);

	str += k - i;
	i = k;
	p = p2;

	if (len)
		*len = str;
	*pnt = p;
	return (str);
}
