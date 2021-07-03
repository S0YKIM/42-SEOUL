/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:39:51 by sokim             #+#    #+#             */
/*   Updated: 2021/07/03 14:21:03 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clear_temp(void)
{
	char	**argv;
	pid_t	pid;

	argv = (char **)malloc(sizeof(char *) * 3);
	if (!argv)
	{
		perror("malloc");
		exit(1);
	}
	argv[0] = "-f";
	argv[1] = "./temp";
	argv[2] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
		execve("/bin/rm", (char *const *)argv, NULL);
}

void	heredoc(const char *limiter)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	write(1, "heredoc> ", 9);
	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(1, "heredoc> ", 9);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	redirect_stdin("./temp");
	close(fd);
	clear_temp();
}
