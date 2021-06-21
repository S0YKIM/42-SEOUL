/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:27:42 by sokim             #+#    #+#             */
/*   Updated: 2021/05/24 17:30:49 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_index_of_newline(char *backup)
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

int		split_line(char **backup, char **line, int newline_index)
{
	char	*temp;
	int		len;

	(*backup)[newline_index] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + newline_index + 1);
	if (!len)
	{
		free(*backup);
		*backup = NULL;
		return (FLAG_SUCCESS);
	}
	temp = ft_strdup(*backup + newline_index + 1);
	free(*backup);
	*backup = temp;
	return (FLAG_SUCCESS);
}

int		end_of_file(char **backup, char **line)
{
	int		newline_index;

	if (!(*backup))
	{
		*line = ft_strdup("");
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

int		get_next_line(int fd, char **line)
{
	static char		*backup[MAX_FD];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				newline_index;

	if (fd < 0 || fd > MAX_FD || !line || BUFFER_SIZE <= 0)
		return (FLAG_ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((newline_index = get_index_of_newline(backup[fd])) >= 0)
			return (split_line(&backup[fd], line, newline_index));
	}
	if (read_size < 0)
		return (FLAG_ERROR);
	return (end_of_file(&backup[fd], line));
}
