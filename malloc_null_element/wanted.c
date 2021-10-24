#include "main.h"

/*
**	len = 10.
**	sizeof(char) = 1 byte.
**
**	WHAT I WANT malloc TO RECEIVE IN ft_char_assign():
**	11 bytes
**
**	WHAT malloc RECEIVES IN ft_char_assign():
**	10 + 1 = 11 * 1 byte = 11 bytes
*/

int	ft_char_assign(char **dst, size_t const len)
{
	if (!dst)
		return (1);
	*dst = malloc(sizeof(char) * (len + 1));
	if (!(*dst))
		return (1);
	(*dst)[len] = 0;
	return (0);
}

/*
**	len = 10.
**	sizeof(int) = 4 bytes.
**
**	WHAT I WANT malloc TO RECEIVE IN ft_int_assign():
**	44 bytes
**
**	WHAT malloc RECEIVES IN ft_char_assign():
**	10 + 1 = 11 * 4 bytes = 44 bytes
*/

int	ft_int_assign(int **dst, size_t const len)
{
	if (!dst)
		return (1);
	*dst = malloc(sizeof(int) * (len + 1));
	if (!(*dst))
		return (1);
	(*dst)[len] = 0;
	return (0);
}
