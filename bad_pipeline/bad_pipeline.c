#include "main.h"

static int	waiter(void)
{
	int		status;
	size_t	i;

	i = 3;
	while (i--)
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (1);
		}
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status))
				strerror(WEXITSTATUS(status));
		}
		if (WIFSTOPPED(status))
			printf("Program stopped.\n");
		if (WIFSIGNALED(status))
			printf("Program interrupted by signal: %d\n", WTERMSIG(status));
	}
	return (0);
}

/*
**	HERE IS THE MISTAKE, I DID NOT FOLLOW THE RULE OF CLOSING
**	THE END OF THE PIPE THAT THE PROCESS WAS NOT GOING TO USE.
**
**	IT IS NOT NECESSARY TO CLOSE THE OTHER END OF THE READ PIPE
**	IN THE CHILD PROCESS BECAUSE THE PARENT PROCESS HAS CLOSED
**	THE OTHER END OF THE READING PIPE BEFORE FORKING THE CHILD
**	THAT WILL RECEIVE IT.
*/

static void	executor(t_program *prog)
{
	if (prog->r_pipe[0] != -1)
	{
		dup2(prog->r_pipe[0], STDIN_FILENO);
		close(prog->r_pipe[0]);
	}
	if (prog->w_pipe[1] != -1)
	{
		//THIS close(prog->w_pipe[0]); WAS MISSING
		dup2(prog->w_pipe[1], STDOUT_FILENO);
		close(prog->w_pipe[1]);
	}
	execve(prog->location, prog->args, NULL);
	perror("program execution");
}

static int	exec_program(t_program *program)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		return (1);
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		executor(program);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	pipe_manager(t_program *prog, int const next)
{
	int			pipe_fd[2];
	static int	prev_0 = -1;
	static int	prev_1 = -1;

	if (prev_0 != -1)
	{
		prog->r_pipe[0] = prev_0;
		prog->r_pipe[1] = prev_1;
	}
	if (next)
	{
		if (pipe(pipe_fd) == -1)
			return (1);
		prog->w_pipe[0] = pipe_fd[0];
		prog->w_pipe[1] = pipe_fd[1];
		prev_0 = pipe_fd[0];
		prev_1 = pipe_fd[1];
	}
	return (0);
}

int	pipeline(t_program **programs)
{
	int		next;
	size_t	i;

	if (!programs || !(*programs))
		return (1);
	i = 0;
	while (programs[i])
	{
		next = 1;
		if (!programs[i + 1])
			next = 0;
		if (pipe_manager(programs[i], next))
			return (1);
		if (exec_program(programs[i]))
			return (1);
		if (programs[i]->r_pipe[0] != -1)
			close(programs[i]->r_pipe[0]);
		if (programs[i]->w_pipe[1] != -1)
			close(programs[i]->w_pipe[1]);
		++i;
	}
	if (waiter())
		return (1);
	return (0);
}
