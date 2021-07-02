/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:27 by sokim             #+#    #+#             */
/*   Updated: 2021/07/02 20:07:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char const *argv[])
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (argc != 5)
		return (0);
	if (pipe(pipefd) == -1)
		return (0);
	pid = fork();
	if (pid > 0)
	{
		redirect_stdout(argv[4]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		connect_pipe(pipefd, STDIN_FILENO);
		run_command(argv[3]);
	}
	else if (pid == 0)
	{
		redirect_stdin(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_command(argv[2]);
	}
	return (0);
}
