#include "main.h"

/*
**	*copy[len] AND *copy[i] ARE INTERPRETED AS *(copy[len]) AND *(copy[i])
**	RESPECTIVELY, INSTEAD OF (*copy)[len] AND (*copy)[i], WHICH IS WHAT
**	I WANTED.
**
**	THIS CODE COMPILES, BUT CAUSES A Segmentation Fault ERROR AT THE THIRD
**	while ITERATION.
*/

int	ft_copy(char **copy, char const *src)
{
	size_t	len;
    size_t	i;

	if (!src || !(*src))
		return (1);
	len = strlen(src);
	*copy = malloc(sizeof(char) * (len + 1));
	if (!(*copy))
		return (1);
	*copy[len] = 0; //NOT WANTED
	i = 0;
	while (src[i])
	{
		*copy[i] = src[i]; //NOT WANTED
		++i;
	}
	return (0);
}
