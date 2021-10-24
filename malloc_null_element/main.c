#include "main.h"
#include <unistd.h>

static void	printer(void const *src, size_t const len, int const type)
{
	int		*i_src;
	size_t	i;

	if (!type)
	{
		printf("str: %s\n", (char *)src);
		return ;
	}
	printf("nums: ");
	i_src = (int *)src;
	i = 0;
	while (i < len)
	{
		printf("%d", i_src[i]);
		++i;
	}
	printf("\n");	
}

static void	int_filler(int *dst, int const start_val, size_t const len)
{
	int		val;
	size_t	i;

	if (!dst)
		return ;
	val = start_val;
	i = 0;
	while (i < len)
	{
		dst[i] = val;
		++i;
		++val;
	}
	return ;
}

static void	char_filler(char *dst, int const start_val, size_t const len)
{
	int		val;
	size_t	i;

	if (!dst)
		return ;
	val = start_val;
	i = 0;
	while (i < len)
	{
		dst[i] = (char)val;
		++i;
		++val;
	}
	return ;
}

int	main(void)
{
	char	*str;
	int		*nums;
	size_t	len;

	str = 0;
	nums = 0;
	len = 10;
	if (ft_char_assign(&str, len))
		return (1);
	char_filler(str, 97, len);
	printer(str, len, 0);
	free(str);
	if (ft_int_assign(&nums, len))
		return (1);
	int_filler(nums, 0, len);
	printer(nums, len, 1);
	free(nums);
	return (0);
}
