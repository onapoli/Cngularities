#include "main.h"

static void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		++i;
	}
	free(args);
	return ;
}

void	free_programs(t_program **programs)
{
	size_t	i;

	i = 0;
	while (programs[i])
	{
		free(programs[i]->location);
		free_args(programs[i]->args);
		free(programs[i]);
		++i;
	}
	free(programs);
	return ;
}
