/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:27 by sokim             #+#    #+#             */
/*   Updated: 2021/07/02 22:40:18 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_cmd(char const **argv, int *pipefd)
{
	if (ft_strcmp("here_doc", argv[1]) == 0)
	{
		heredoc(argv[2]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_command(argv[3]);
	}
	else
	{
		redirect_stdin(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_command(argv[2]);
	}
}

static void	mid_cmd(pid_t pid, char const *argv, int *old_pipe, int *new_pipe)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 0)
		exit(1);
	connect_pipe(new_pipe, STDIN_FILENO);
	connect_pipe(old_pipe, STDOUT_FILENO);
	run_command(argv);
}

static void	last_cmd(pid_t pid, char const **argv, int argc, int *pipefd)
{
	int		status;

	if (ft_strcmp("here_doc", argv[1]) == 0)
		redirect_stdout_add(argv[argc - 1]);
	else
		redirect_stdout(argv[argc - 1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 0)
		exit(1);
	connect_pipe(pipefd, STDIN_FILENO);
	run_command(argv[argc - 2]);
}

static void	make_child(const char **argv, int npipes, int *old_pipe, int depth)
{
	int		new_pipe[2];
	pid_t	pid;

	if (depth == npipes)
		first_cmd(argv, old_pipe);
	else
	{
		if (pipe(new_pipe) == -1)
		{
			perror("pipe: make_child");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork: make_child");
			exit(1);
		}
		else if (pid > 0)
			mid_cmd(pid, argv[npipes + 2 - depth], old_pipe, new_pipe);
		else if (pid == 0)
			make_child(argv, npipes, new_pipe, depth + 1);
	}
}

int			main(int argc, char const *argv[])
{
	int		pipefd[2];
	pid_t	pid;

	if ((argc < 5) || ((argc < 6) && (ft_strcmp("here_doc", argv[1]) == 0)))
		return (0);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (0);
	}
	pid = fork();
	if (pid > 0)
		last_cmd(pid, argv, argc, pipefd);
	else if (pid == 0)
	{
		if (ft_strcmp("here_doc", argv[1]) == 0)
			make_child(argv, argc - 5, pipefd, 1);
		else
			make_child(argv, argc - 4, pipefd, 1);
	}
	perror("fork");
	return (0);
}
