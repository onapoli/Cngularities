#include "main.h"

static void	clean_exit(int const code, t_program **programs)
{
	if (programs)
		free_programs(programs);
	exit(code);
}

int	main(int argc, char **argv)
{
	t_program	**programs;
	int			selection;

	if (argc != 2 || strlen(argv[1]) != 1
		|| (*(argv[1]) != 'a' && *(argv[1]) != 'b'))
	{
		printf("Enter a or b as program argument.\n");
		return (1);
	}
	programs = malloc(sizeof(t_program *) * (3 + 1));
	if (!programs)
		return (1);
	programs[3] = 0;
	selection = *(argv[1]);
	if (init_programs(programs, selection))
		return (1);
	signal(SIGINT, SIG_IGN);
	if (pipeline(programs))
		clean_exit(EXIT_FAILURE, programs);
	clean_exit(EXIT_SUCCESS, programs);
}
