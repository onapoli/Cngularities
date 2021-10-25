# include <stdio.h>
# include <string.h>

static size_t	word_len(char const *str)
{
	char	*needle;
	size_t	len;

	len = 0;
	if (!str || !(*str))
		return (len);
	needle = strchr(str, ' ');
	if (!needle)
		len = strlen(str);
	else
		len = needle - str;
	return (len);
}

int	main(void)
{
	char const *str = "Hello $USER. Hello $SHELL. How are you$?";
	char	*needle_a;
	char	*needle_b;
	size_t	i;

	needle_a = (char *)str;
	needle_b = 0;
	i = 0;
	while (*needle_a)
	{
		needle_b = strchr(needle_a, '$');
		if (!needle_b)
			break ;
		printf("\n-- $ No. %ld --\n", i);
		printf("pos from begin: %ld\n", needle_b - str);
		if (i)
			printf("pos from last $: %ld\n", needle_b - needle_a);
		printf("word length: %ld\n", word_len(needle_b + 1));
		needle_a = needle_b + 1;
		++i;
	}
	return (0);
}
