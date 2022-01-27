/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:15:35 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 14:34:19 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_new_window(void *mlx, t_map *map, t_data *data)
{	
	data->win = mlx_new_window(mlx, map->window_width, \
		map->window_height, "so_long");
	if (!(data->win))
		sl_exit_with_message("Error\nFailed to create new window.\n", data);
}
