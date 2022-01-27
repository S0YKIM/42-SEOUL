/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:37:56 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 19:28:29 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			else if (data->map.map[j][i] == 'A')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->imgs.enemy.img, i * 32, j * 32);
			j++;
		}
		i++;
	}
}

static void	sl_show_move_counts(t_data *data)
{
	char	*cnt;
	int		x;
	int		y;

	cnt = ft_itoa(data->state.move_cnt);
	if (!cnt)
		sl_exit_with_message("Error\nItoa error.\n", data);
	x = data->state.player.x * 32;
	y = data->state.player.y * 32;
	mlx_string_put(data->mlx, data->win, x, y, 0x0D0D0D, cnt);
	free(cnt);
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
	sl_show_move_counts(data);
}
