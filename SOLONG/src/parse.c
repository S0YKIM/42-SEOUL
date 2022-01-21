/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:31 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 20:48:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_open_file(char *filename, t_data *data)
{
	int		fd;

	if (!filename)
		sl_exit_with_message("Invalid file name.", data);
	fd = open(filename, O_RDONLY, S_IRUSR);
	if (fd < 0)
		sl_exit_with_message("Failed to open the file.", data);
	return (fd);
}

int	sl_parse_map(t_map *map, char *filename, t_data *data)
{
	int		fd;
	char	*raw;
	char	*line;

	fd = sl_open_file(filename, data);
	raw = ft_strdup("");
	while (get_next_line(fd, &line) > FLAG_EOF)
	{
		raw = ft_strjoin(raw, line);
		raw = ft_strjoin(raw, "\n");
		map->height++;
	}
	map->map = ft_split(raw, '\n');
	free(raw);
	map->width = ft_strlen(map->map[0]);
	map->window_width = map->width * 32;
	map->window_height = map->height * 32;
	return (1);
}
