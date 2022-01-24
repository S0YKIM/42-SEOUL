/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:38:02 by sokim             #+#    #+#             */
/*   Updated: 2022/01/24 21:55:13 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sl_is_possible_to_move(t_data *data, t_position player)
{
	if (sl_get_char(data, player) == 'W')
		return (0)
	else if (sl_get_char(data, player) == 'C')
	{
		data->map.map[player.y][player.x] = '0';
		data->state.collect_cnt--;
	}
	else if (sl_get_char(data, player) == 'E' &&
			data->state.collect_cnt == 0)
	{
		sl_exit_with_message("Congrats! Game ended.", data);
	}
	return (1);
}
