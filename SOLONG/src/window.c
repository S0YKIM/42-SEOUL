/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:15:35 by sokim             #+#    #+#             */
/*   Updated: 2022/01/19 21:26:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_new_window(t_data *data)
{
	void	*mlx;
	void	*win;
	t_map	map;

	mlx = data->mlx;
	win = data->win;
	map = data->map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, map.window_width, map.window_height, "so_long");
	mlx_loop(mlx);
}
