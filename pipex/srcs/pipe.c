/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:40:54 by sokim             #+#    #+#             */
/*   Updated: 2021/07/02 15:53:52 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	connect_pipe(int pipefd[2], int io)
{
	if (dup2(pipefd[io], io) < 0)
	{
		perror("dup2_connect_pipe");
		exit(1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}
