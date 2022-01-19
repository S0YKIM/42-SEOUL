/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:31 by sokim             #+#    #+#             */
/*   Updated: 2022/01/19 17:14:27 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_parse_map(t_map *map, char *filename)
{
	int		fd;
	char	*raw;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
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
	map->screen_width = 1600;
	map->screen_height = 900;
	return (1);
}
