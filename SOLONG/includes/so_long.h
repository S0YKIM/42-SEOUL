/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:40 by sokim             #+#    #+#             */
/*   Updated: 2022/01/19 19:26:55 by sokim            ###   ########.fr       */
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

int		sl_parse_map(t_map *map, char *filename);

/* Map validation check */

int		sl_is_validate_map(t_map *map);

/* New window */

void	sl_new_window(t_data *data);

#endif
