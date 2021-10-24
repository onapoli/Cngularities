#include "main.h"

int	main(void)
{
    char *res;

	res = 0;
    if (ft_copy(&res, "Hello"))
		return (1);
    printf("copy: %s\n", res);
    free(res);
    return (0);
}
