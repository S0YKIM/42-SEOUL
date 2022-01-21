/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:40 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 20:52:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "so_long_macro.h"
# include "so_long_type.h"

/* Map parsing */

int		sl_parse_map(t_map *map, char *filename, t_data *data);

/* Map validation check */

int		sl_is_validate_map(t_data *data);

/* New window */

void	sl_new_window(void *mlx, t_map *map, t_data *data);

/* New image */

void	sl_new_image(t_data *data);

/* Exit with message */

void	sl_exit_with_message(char *msg, t_data *data);

#endif
