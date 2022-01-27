/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:40 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 20:11:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "so_long_macro_bonus.h"
# include "so_long_type_bonus.h"

/* Map parsing */

int		sl_parse_map(t_map *map, char *filename, t_data *data);

/* Map validation check */

int		sl_is_validate_map(t_data *data);

/* New window */

void	sl_new_window(void *mlx, t_map *map, t_data *data);

/* New image */

void	sl_new_image(t_data *data);

/* Draw pixel */

void	sl_pixel_put_img(t_img_info *img, int x, int y, int color);

void	sl_draw_map(t_data *data);

/* Event hook */

int		sl_key_hook(int keycode, t_data *data);

/* Utilities */

int		sl_is_possible_to_move(t_data *data, t_position player);
void	sl_print_move_count(t_data *data);

/* Game end */

void	sl_exit_with_message(char *msg, t_data *data);
int		sl_exit_with_button_close(t_data *data);

#endif
