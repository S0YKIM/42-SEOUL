/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:14:21 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 20:55:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_save_image(t_data *data)
{
	int	width;
	int	height;

	data->imgs.back.img = mlx_xpm_file_to_image(data->mlx, "img/empty.xpm", &width, &height);
	data->imgs.wall.img = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &width, &height);
	data->imgs.player.img = mlx_xpm_file_to_image(data->mlx, "img/worm.xpm", &width, &height);
	data->imgs.collects.img = mlx_xpm_file_to_image(data->mlx, "img/apple.xpm", &width, &height);
	data->imgs.exit.img = mlx_xpm_file_to_image(data->mlx, "img/ladder.xpm", &width, &height);
	if (!(data->imgs.back.img) || !(data->imgs.wall.img)
	|| !(data->imgs.player.img) || !(data->imgs.collects.img)
	|| !(data->imgs.exit.img))
		sl_exit_with_message("Failed to save image path.", data);
}

static void	sl_get_image_address(t_imgs *imgs, t_data *data)
{
	imgs->back.addr = mlx_get_data_addr(imgs->back.img, &imgs->back.bpp, &imgs->back.line_length, &imgs->back.endian);
	imgs->wall.addr = mlx_get_data_addr(imgs->wall.img, &imgs->wall.bpp, &imgs->wall.line_length, &imgs->wall.endian);
	imgs->player.addr = mlx_get_data_addr(imgs->player.img, &imgs->player.bpp, &imgs->player.line_length, &imgs->player.endian);
	imgs->collects.addr = mlx_get_data_addr(imgs->collects.img, &imgs->collects.bpp, &imgs->collects.line_length, &imgs->collects.endian);
	imgs->exit.addr = mlx_get_data_addr(imgs->exit.img, &imgs->exit.bpp, &imgs->exit.line_length, &imgs->exit.endian);
	if (!(imgs->back.addr) || !(imgs->wall.addr)
		|| !(imgs->player.addr) || !(imgs->collects.addr)
		|| !(imgs->exit.addr))
		sl_exit_with_message("Failed to save image info.", data);
}

void	sl_new_image(t_data *data)
{
	sl_save_image(data);
	sl_get_image_address(&data->imgs, data);
}
