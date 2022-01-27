/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:29 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 14:12:41 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		sl_exit_with_message("Error:\nFailed to initialize.\n", data);
	data->win = 0;
	data->count = 0;
	data->map.map = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->imgs.back.img = 0;
	data->imgs.wall.img = 0;
	data->imgs.player.img = 0;
	data->imgs.collects.img = 0;
	data->imgs.exit.img = 0;
	data->state.collect_cnt = 0;
	data->state.move_cnt = 0;
}

void	so_long(char *filename)
{
	t_data	data;

	sl_init_data(&data);
	sl_parse_map(&(data.map), filename, &data);
	sl_is_validate_map(&data);
	sl_new_window(data.mlx, &(data.map), &data);
	sl_new_image(&data);
	mlx_key_hook(data.win, &sl_key_hook, &data);
	mlx_hook(data.win, BUTTON_CLOSE, 0, &sl_exit_with_button_close, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("Error:\nInvalid number of arguments.\n");
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		printf("Error:\nInvalid file format.\n");
	else
		so_long(argv[1]);
	return (0);
}
