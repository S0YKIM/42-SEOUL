/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:27 by sokim             #+#    #+#             */
/*   Updated: 2021/07/01 17:40:14 by sokim            ###   ########.fr       */
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
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_stdout(argv[4]);
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
