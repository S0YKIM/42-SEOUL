/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:27:42 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 13:42:06 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_index_of_newline(char *backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		++i;
	}
	return (FLAG_ERROR);
}

static int	split_line(char **backup, char **line, int nl_index)
{
	char	*temp;
	int		len;

	(*backup)[nl_index] = '\0';
	*line = ft_strdup(*backup);
	if (!(*line))
		return (FLAG_ERROR);
	len = ft_strlen(*backup + nl_index + 1);
	if (!len)
	{
		free(*backup);
		*backup = NULL;
		return (FLAG_SUCCESS);
	}
	temp = ft_strdup(*backup + nl_index + 1);
	if (!temp)
		return (FLAG_ERROR);
	free(*backup);
	*backup = temp;
	return (FLAG_SUCCESS);
}

static int	end_of_file(char **backup, char **line)
{
	int		nl_index;

	if (!(*backup))
	{
		*line = ft_strdup("");
		if (!(*line))
			return (FLAG_ERROR);
		return (FLAG_EOF);
	}
	nl_index = get_index_of_newline(*backup);
	if (nl_index >= 0)
		return (split_line(backup, line, nl_index));
	else
	{
		*line = *backup;
		*backup = NULL;
		return (FLAG_EOF);
	}
}

int	get_next_line(int fd, char **line)
{
	static char		*backup[MAX_FD];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				nl_index;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (FLAG_ERROR);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		backup[fd] = ft_strjoin_free(backup[fd], buf, 'L');
		nl_index = get_index_of_newline(backup[fd]);
		if (nl_index >= 0)
			return (split_line(&backup[fd], line, nl_index));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (end_of_file(&backup[fd], line));
}
