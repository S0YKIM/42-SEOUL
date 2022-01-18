/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:40 by sokim             #+#    #+#             */
/*   Updated: 2022/01/18 16:08:25 by sokim            ###   ########.fr       */
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


#endif
