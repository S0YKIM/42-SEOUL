/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:31 by sokim             #+#    #+#             */
/*   Updated: 2022/01/24 21:58:43 by sokim            ###   ########.fr       */
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

static t_state	sl_get_player_position(t_map *map)
{
	t_state	position;
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	position.x = -1;
	position.y = -1;
	return (position);
}

static void	sl_init_data_plus(t_data *data)
{
	data->window_width = data->width * 32;
	data->window_height = data->height * 32;
	data->state.player = sl_get_player_position(&data->map);
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
	sl_init_data_plus(data);
	return (1);
}
