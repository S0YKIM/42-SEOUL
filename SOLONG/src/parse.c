/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:31 by sokim             #+#    #+#             */
/*   Updated: 2022/01/26 21:56:06 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_open_file(char *filename, t_data *data)
{
	int		fd;

	if (!filename)
		sl_exit_with_message("Error:\nInvalid file name.\n", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		sl_exit_with_message("Error:\nFailed to open the file.\n", data);
	return (fd);
}

static t_position	sl_get_player_position(t_map *map)
{
	t_position	position;
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
	data->map.window_width = data->map.width * 32;
	data->map.window_height = data->map.height * 32;
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
		raw = ft_strjoin_free(raw, line, 'B');
		raw = ft_strjoin_free(raw, "\n", 'L');
		map->height++;
	}
	free(line);
	if (map->height == 0)
		sl_exit_with_message("Error: \nEmpty map.\n", data);
	map->map = ft_split(raw, '\n');
	free(raw);
	map->width = ft_strlen(map->map[0]);
	sl_init_data_plus(data);
	return (1);
}
