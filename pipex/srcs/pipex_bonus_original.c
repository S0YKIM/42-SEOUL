/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:27 by sokim             #+#    #+#             */
/*   Updated: 2021/06/30 21:55:13 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(char const **argv, int *pipefd)
{
	redirect_stdin(argv[1]);
	connect_pipe(pipefd, STDOUT_FILENO);
	run_command(argv[2]);
}

static void	mid_cmd(pid_t pid, char const *argv, int *old_pipe, int *new_pipe)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 0)
		exit(1);
	if (dup2(new_pipe[0], STDIN_FILENO) < 0)
		perror("dup2: middle_process");
	close(new_pipe[0]);
	close(new_pipe[1]);
	if (dup2(old_pipe[1], STDOUT_FILENO) < 0)
		perror("dup2: middle_process");
	close(old_pipe[0]);
	close(old_pipe[1]);
	run_command(argv);
}

static void	last_cmd(pid_t pid, char const **argv, int argc, int *pipefd)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 0)
		exit(1);
	redirect_stdout(argv[argc - 1]);
	connect_pipe(pipefd, STDIN_FILENO);
	run_command(argv[argc - 2]);
}

static void	make_child(const char **argv, int argc, int *old_pipe, int depth)
{
	int		new_pipe[2];
	int		npipes;
	pid_t	pid;

	npipes = argc - 4;
	if (depth == npipes)
		first_cmd(argv, old_pipe);
	else
	{
		if (pipe(new_pipe) == -1)
			perror("pipe");
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid > 0)
			mid_cmd(pid, argv[argc - (depth + 2)], old_pipe, new_pipe);
		else if (pid == 0)
			make_child(argv, argc, new_pipe, depth + 1);
	}
}

int			main(int argc, char const *argv[])
{
	int		pipefd[2];
	pid_t	pid;

	if (argc < 5)
		return (0);
	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
		last_cmd(pid, argv, argc, pipefd);
	else if (pid == 0)
		make_child(argv, argc, pipefd, 1);
	return (0);
}
