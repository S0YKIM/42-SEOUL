/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:09:42 by sokim             #+#    #+#             */
/*   Updated: 2022/01/26 17:51:28 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_move_up(t_data *data)
{
	t_position	player;

	player.x = data->state.player.x;
	player.y = data->state.player.y - 1;
	if (!sl_is_possible_to_move(data, player))
		return ;
	data->map.map[player.y][player.x] = 'P';
	data->map.map[player.y + 1][player.x] = '0';
	data->state.player.y--;
	data->state.move_cnt++;
	sl_print_move_count(data);
}

static void	sl_move_down(t_data *data)
{
	t_position	player;

	player.x = data->state.player.x;
	player.y = data->state.player.y + 1;
	if (!sl_is_possible_to_move(data, player))
		return ;
	data->map.map[player.y][player.x] = 'P';
	data->map.map[player.y - 1][player.x] = '0';
	data->state.player.y++;
	data->state.move_cnt++;
	sl_print_move_count(data);
}

static void	sl_move_left(t_data *data)
{
	t_position	player;

	player.x = data->state.player.x - 1;
	player.y = data->state.player.y;
	if (!sl_is_possible_to_move(data, player))
		return ;
	data->map.map[player.y][player.x] = 'P';
	data->map.map[player.y][player.x + 1] = '0';
	data->state.player.x--;
	data->state.move_cnt++;
	sl_print_move_count(data);
}

static void	sl_move_right(t_data *data)
{
	t_position	player;

	player.x = data->state.player.x + 1;
	player.y = data->state.player.y;
	if (!sl_is_possible_to_move(data, player))
		return ;
	data->map.map[player.y][player.x] = 'P';
	data->map.map[player.y][player.x - 1] = '0';
	data->state.player.x++;
	data->state.move_cnt++;
	sl_print_move_count(data);
}

int	sl_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		sl_move_up(data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		sl_move_down(data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		sl_move_left(data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		sl_move_right(data);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
		sl_exit_with_message("You quit the game.\n", data);
	sl_draw_map(data);
	return (0);
}
