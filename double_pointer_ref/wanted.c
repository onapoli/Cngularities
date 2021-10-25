#include "main.h"

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
	(*copy)[len] = 0;
	i = 0;
	while (src[i])
	{
		(*copy)[i] = src[i];
		++i;
	}
	return (0);
}
