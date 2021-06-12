/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:59:21 by sokim             #+#    #+#             */
/*   Updated: 2021/06/11 19:59:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tag(t_tag *tag)
{
	tag->minus = 0;
	tag->zero = 0;
	tag->star = 0;
	tag->plus = 0;
	tag->space = 0;
	tag->hashtag = 0;
	tag->width = 0;
	tag->precision = -1;
	tag->type = 0;
	tag->nbr_base = 10;
	tag->nbr_sign = 1;
}

void	init_width(t_tag *tag)
{
	if (tag->star == 1)
	{
		tag->width = 0;
		tag->star = 0;
	}
	return ;
}

void	init_precision(t_tag *tag)
{
	if (tag->star == 1)
	{
		tag->precision = 0;
		tag->star = 0;
	}
	return ;
}
