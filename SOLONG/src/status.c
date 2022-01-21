/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:35 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 20:59:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void sl_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

static void	sl_destroy_window_images(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->imgs.back.img)
		mlx_destroy_image(data->mlx, data->imgs.back.img);
	if (data->imgs.wall.img)
		mlx_destroy_image(data->mlx, data->imgs.wall.img);
	if (data->imgs.player.img)
		mlx_destroy_image(data->mlx, data->imgs.player.img);
	if (data->imgs.collects.img)
		mlx_destroy_image(data->mlx, data->imgs.collects.img);
}

void	sl_exit_with_message(char *msg, t_data *data)
{
	printf("%s\n", msg);
	if (data->map.map)
		sl_free_map(data->map.map);
	sl_destroy_window_images(data);
	exit (0);
}
