/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:28:37 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 17:31:26 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPE_H
# define SO_LONG_TYPE_H

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
}	t_imgs;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		count;
	t_map	map;
	t_imgs	imgs;
}	t_data;

#endif
