/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:37:56 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 14:09:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_draw_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.width)
	{
		j = 0;
		while (j < data->map.height)
		{
			mlx_put_image_to_window(data->mlx, data->win, \
					data->imgs.back.img, i * 32, j * 32);
			if (data->map.map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->imgs.wall.img, i * 32, j * 32);
			j++;
		}
		i++;
	}
}

void	sl_draw_map(t_data *data)
{
	int	i;
	int	j;

	sl_draw_background(data);
	i = 0;
	while (i < data->map.width)
	{
		j = 0;
		while (j < data->map.height)
		{
			if (data->map.map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs.exit.img, i * 32, j * 32);
			else if (data->map.map[j][i] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs.player.img, i * 32, j * 32);
			else if (data->map.map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs.collects.img, i * 32, j * 32);
			j++;
		}
		i++;
	}
}
