/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:32:56 by sokim             #+#    #+#             */
/*   Updated: 2021/07/03 21:08:38 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	select_path_to_command(const char *cmd, t_path *strc)
{
	char	**chunk;

	chunk = ft_split(cmd, ' ');
	if (!chunk)
		exit(1);
	strc->path[0] = ft_strjoin("/usr/local/bin/", chunk[0]);
	if (!strc->path[0])
		exit(1);
	strc->path[1] = ft_strjoin("/usr/bin/", chunk[0]);
	if (!strc->path[1])
		exit(1);
	strc->path[2] = ft_strjoin("/bin/", chunk[0]);
	if (!strc->path[2])
		exit(1);
	strc->path[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	if (!strc->path[3])
		exit(1);
	strc->path[4] = ft_strjoin("/sbin/", chunk[0]);
	if (!strc->path[4])
		exit(1);
	strc->path[5] = ft_strjoin("", chunk[0]);
	if (!strc->path[5])
		exit(1);
	strc->argv = (char *const *)chunk;
}

static void	select_path_to_command_with_awk(const char *cmd, t_path *strc)
{
	char	**chunk;

	chunk = ft_split_with_awk(cmd);
	if (!chunk)
		exit(1);
	strc->path[0] = ft_strjoin("/usr/local/bin/", chunk[0]);
	if (!strc->path[0])
		exit(1);
	strc->path[1] = ft_strjoin("/usr/bin/", chunk[0]);
	if (!strc->path[1])
		exit(1);
	strc->path[2] = ft_strjoin("/bin/", chunk[0]);
	if (!strc->path[2])
		exit(1);
	strc->path[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	if (!strc->path[3])
		exit(1);
	strc->path[4] = ft_strjoin("/sbin/", chunk[0]);
	if (!strc->path[4])
		exit(1);
	strc->path[5] = ft_strjoin("", chunk[0]);
	if (!strc->path[5])
		exit(1);
	strc->argv = (char *const *)chunk;
}

void	run_command(const char *cmd)
{
	int		i;
	t_path	strc;

	i = 0;
	if (ft_strncmp("awk ", cmd, 4) == 0)
		select_path_to_command_with_awk(cmd, &strc);
	else
		select_path_to_command(cmd, &strc);
	while (i < 6)
	{
		execve(strc.path[i], strc.argv, NULL);
		free((void *)strc.path[i++]);
	}
	free((void *)strc.argv);
	perror("command not found");
	exit(1);
}
