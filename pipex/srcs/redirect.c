/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:21:20 by sokim             #+#    #+#             */
/*   Updated: 2021/07/01 21:47:12 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdin(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		perror("redirect_stdin");
	close(fd);
}

void	redirect_stdout(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror("redirect_stdout");
	close(fd);
}
