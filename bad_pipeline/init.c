#include "main.h"

static int	init_args(char ***args, char const *location, char const *arg)
{
	size_t	len;

	len = 1;
	if (arg && *arg)
		++len;
	*args = malloc(sizeof(char *) * (len + 1));
	if (!(*args))
		return (1);
	(*args)[len] = 0;
	(*args)[0] = strdup(location);
	if (len == 2)
		(*args)[1] = strdup(arg);
	return (0);
}

int	init_programs(t_program **progs, int const selection)
{
	char const	*locations_a[4] = {"/bin/ls", "/bin/grep", "/usr/bin/wc", 0};
	char const	*locations_b[4] = {"/bin/cat", "/bin/cat", "/bin/ls", 0};
	char const	*args_a[4] = {"/usr", "i", "", 0};
	char const	*args_b[4] = {"", "", "/usr", 0};
	char		**locations;
	char		**args;
	t_program	*new_prog;
	size_t		i;

	if (selection == 'a')
	{
		locations = (char **)locations_a;
		args = (char **)args_a;
	}
	else
	{
		locations = (char **)locations_b;
		args = (char **)args_b;
	}
	i = 0;
	while (locations[i])
	{
		new_prog = malloc(sizeof(t_program));
		if (!new_prog)
			return (1);
		new_prog->location = strdup(locations[i]);
		if (init_args(&(new_prog->args), locations[i], args[i]))
			return (1);
		new_prog->r_pipe[0] = -1;
		new_prog->r_pipe[1] = -1;
		new_prog->w_pipe[0] = -1;
		new_prog->w_pipe[1] = -1;
		progs[i] = new_prog;
		++i;
	}
	return (0);
}
