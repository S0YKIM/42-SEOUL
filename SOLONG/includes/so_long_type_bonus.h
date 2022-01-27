/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_type_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:28:37 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 20:13:01 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPE_BONUS_H
# define SO_LONG_TYPE_BONUS_H

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_info;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		window_width;
	int		window_height;
}	t_map;

typedef struct s_imgs
{
	t_img_info	back;
	t_img_info	wall;
	t_img_info	player;
	t_img_info	collects;
	t_img_info	exit;
	t_img_info	enemy;
}	t_imgs;

typedef struct s_state
{
	t_position	player;
	int			collect_cnt;
	int			move_cnt;
}	t_state;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_imgs	imgs;
	t_state	state;
}	t_data;

#endif
