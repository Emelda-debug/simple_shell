#include "main.h"
/**
 * _realloc- reallocate memory
 * @p: pointer to previous block
 * @o: previous block size
 * @n: new block size
 * Return: pointer to old block
 */
void *_realloc(void *p, unsigned int o, unsigned int n)
{
	char *pnt;

	if (!p)
	{
		return (malloc(n));
	}
	if (!n)
	{
		return (free(p), NULL);
	}
	if (n == o)
	{
		return (p);
	}
	pnt = malloc(n);
	if (!pnt)
	{
		return (NULL);
	}
	o = o < n ? o : n;
	while (o--)
	{
		pnt[o] = ((char *)p) [o];
	}
	free(p);
	return (pnt);
}


