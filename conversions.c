#include "main.h"
/**
 * is_delim - checks if character is a delimeter or not
 * @ch: the char to check
 * @del: delimeter string
 * Return: 1 for true, 0 otherwise
 */
int is_delim(char ch, char *del)
{
	while (*del)
	{
		if (*del++ == ch)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _atoi - converts a string to an integer
 * @sc: converted string
 * Return: converted number
 */
int _atoi(char *sc)
{
	int x, sign = 1, f = 0, o;
	unsigned int r = 0;

	for (x = 0;  sc[x] != '\0' && f != 2; x++)
	{
		if (sc[x] == '-')
		{
			sign = sign * -1;
		}
		if (sc[x] >= '0' && sc[x] <= '9')
		{
			f = 1;
			r = r * 10;
			r = r + (sc[x] - '0');
		}
		else if (f == 1)
		{
			f = 2;
		}
	}
	if (sign == -1)
	{
		o = -r;
	}
	else
	{
		o = r;
	}
	return (o);
}
/**
 * isalphabet- checks for alphabetical character
 * @q: input character
 * Return: 1 if q is alphabet or 0
 */
int isalphabet(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
