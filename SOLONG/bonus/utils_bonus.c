/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:38:02 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 20:06:16 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	sl_get_char(t_data *data, t_position pos)
{
	return (data->map.map[pos.y][pos.x]);
}

int	sl_is_possible_to_move(t_data *data, t_position player)
{
	if (sl_get_char(data, player) == '1')
		return (0);
	else if (sl_get_char(data, player) == 'C')
	{
		data->map.map[player.y][player.x] = '0';
		data->state.collect_cnt--;
	}
	else if (sl_get_char(data, player) == 'A')
	{
		data->state.move_cnt++;
		sl_print_move_count(data);
		sl_exit_with_message("Oops! Try again.\n", data);
	}
	else if (sl_get_char(data, player) == 'E'
		&& data->state.collect_cnt == 0)
	{
		data->state.move_cnt++;
		sl_print_move_count(data);
		sl_exit_with_message("Congrats! The end.\n", data);
	}
	else if (sl_get_char(data, player) == 'E'
		& data->state.collect_cnt != 0)
		return (0);
	return (1);
}

void	sl_print_move_count(t_data *data)
{
	printf("Move counts: %i\n", data->state.move_cnt);
}
