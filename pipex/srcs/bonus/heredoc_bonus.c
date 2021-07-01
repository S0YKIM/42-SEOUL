/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:39:51 by sokim             #+#    #+#             */
/*   Updated: 2021/07/01 22:19:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clear_temp(void)
{
	char	**argv;

	argv = malloc(sizeof(char *) * 3);
	argv[0] = "-f";
	argv[1] = "./temp";
	argv[2] = NULL;
	if (fork() == 0)
		execve("/bin/rm", (char *const *)argv, NULL);
}

void		heredoc(const char *limiter)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(1, "heredoc> ", 9);
	while (get_next_line(0, &buf) != 0)
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
