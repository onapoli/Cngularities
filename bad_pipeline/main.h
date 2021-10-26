#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_program
{
	int		r_pipe[2];
	int		w_pipe[2];
	char	*location;
	char	**args;
}				t_program;

/*
**	AT good_pipeline.c AND bad_pipe_line.c
*/

int		pipeline(t_program **programs);

/*
**	AT init.c
*/

int		init_programs(t_program **progs, int const selection);

/*
**	AT free.c
*/

void	free_programs(t_program **programs);

#endif
