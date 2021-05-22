/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:40:46 by sokim             #+#    #+#             */
/*   Updated: 2021/05/22 22:28:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_newline_index(char *backup)
{
	int				i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int		split_line(char **backup, char **line, int index)
{
	char			*temp;
	int				len;

	(*backup)[index] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + index + 1);
	if (!len)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	temp = ft_strdup(*backup + index + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		return_all(char **backup, char **line, int read_size)
{
	int				index;

	if (read_size < 0)
		return (-1);
	if (*backup && (index = get_newline_index(*backup) >= 0))
		return (split_line(backup, line, index));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[256];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				index;

	if ((fd < 0 || fd > 256 || !line || (BUFFER_SIZE <= 0)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((index = get_newline_index(backup[fd])) >= 0)
			return (split_line(&backup[fd], line, index));
	}
	return (return_all(&backup[fd], line, read_size));
}

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(int fd, char **line);

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if ((fd = open("/Users/sokim/gnl/42TESTERS-GNL/files/alphabet", O_RDONLY)) == -1)
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}
