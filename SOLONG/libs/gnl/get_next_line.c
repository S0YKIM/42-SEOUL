/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:27:42 by sokim             #+#    #+#             */
/*   Updated: 2021/07/03 15:20:52 by sokim            ###   ########.fr       */
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

static int	split_line(char **buf, char **backup, char **line, int nl_index)
{
	char	*temp;
	int		len;

	free(*buf);
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

static int	end_of_file(char **buf, char **backup, char **line)
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
		return (split_line(buf, backup, line, nl_index));
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
	char			*buf;
	char			*temp;
	int				read_size;
	int				nl_index;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (FLAG_ERROR);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buf);
		free(temp);
		nl_index = get_index_of_newline(backup[fd]);
		if (nl_index >= 0)
			return (split_line(&buf, &backup[fd], line, nl_index));
	}
	free(buf);
	return (end_of_file(&buf, &backup[fd], line));
}
