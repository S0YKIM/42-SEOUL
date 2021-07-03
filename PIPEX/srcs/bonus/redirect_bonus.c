/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:21:20 by sokim             #+#    #+#             */
/*   Updated: 2021/07/02 16:21:09 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	{
		perror("dup2: redirect_stdin");
		exit(1);
	}
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
	{
		perror("dup2: redirect_stdout");
		exit(1);
	}
	close(fd);
}

void	redirect_stdout_add(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2: redirect_stdout_add");
		exit(1);
	}
	close(fd);
}
