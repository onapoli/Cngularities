#include "main.h"

/*
**	THESE FUNCTIONS COMPILE WITHOUT ERRORS OR WARNINGS AND SEEM TO WORK
**	CORRECTLY WHEN EXECUTED. BUT IF A PROGRAM THAT USES THEM IS EXECUTED
**	WITH valgrind, IT WILL THROW THIS ERROR:
**
**	Invalid write of size 4
**	at: ft_int_assign
**
**	CORRESPONDING TO THE WRITE AT LINE 54 THAT IS WRITING OUTSIDE THE BLOCK
**	OF MEMORY ASSIGNED TO *dst:
**	(*dst)[len] = 0;
**
*/

/*
**	len = 10.
**	sizeof(char) = 1 byte.
**
**	WHAT I WANT malloc TO RECEIVE IN ft_char_assign():
**	11 bytes
**
**	WHAT malloc RECEIVES IN ft_char_assign():
**	1 * 10 = 10 + 1 = 11 bytes
*/

int	ft_char_assign(char **dst, size_t const len)
{
	if (!dst)
		return (1);
	*dst = malloc(sizeof(char) * len + 1);
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
**	4 * 10 = 40 + 1 = 41 bytes
*/

int	ft_int_assign(int **dst, size_t const len)
{
	if (!dst)
		return (1);
	*dst = malloc(sizeof(int) * len + 1); //NOT WANTED
	if (!(*dst))
		return (1);
	(*dst)[len] = 0;
	return (0);
}
