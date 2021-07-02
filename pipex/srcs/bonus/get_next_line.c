/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:27:42 by sokim             #+#    #+#             */
/*   Updated: 2021/07/02 16:16:36 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		get_index_of_newline(char *backup)
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

static int		split_line(char **backup, char **line, int newline_index)
{
	char	*temp;
	int		len;

	(*backup)[newline_index] = '\0';
	if (!(*line = ft_strdup(*backup)))
		return (FLAG_ERROR);
	len = ft_strlen(*backup + newline_index + 1);
	if (!len)
	{
		free(*backup);
		*backup = NULL;
		return (FLAG_SUCCESS);
	}
	if (!(temp = ft_strdup(*backup + newline_index + 1)))
		return (FLAG_ERROR);
	free(*backup);
	*backup = temp;
	return (FLAG_SUCCESS);
}

static int		end_of_file(char **backup, char **line)
{
	int		newline_index;

	if (!(*backup))
	{
		if (!(*line = ft_strdup("")))
			return (FLAG_ERROR);
		return (FLAG_EOF);
	}
	if ((newline_index = get_index_of_newline(*backup)) >= 0)
		return (split_line(backup, line, newline_index));
	else
	{
		*line = *backup;
		*backup = NULL;
		return (FLAG_EOF);
	}
}

int				get_next_line(int fd, char **line)
{
	static char		*backup[MAX_FD];
	char			*buf;
	char			*temp;
	int				read_size;
	int				newline_index;

	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (FLAG_ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buf);
		free(temp);
		if ((newline_index = get_index_of_newline(backup[fd])) >= 0)
		{
			free(buf);
			return (split_line(&backup[fd], line, newline_index));
		}
	}
	free(buf);
	return (end_of_file(&backup[fd], line));
}
