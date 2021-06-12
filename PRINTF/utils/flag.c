/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:15:34 by sokim             #+#    #+#             */
/*   Updated: 2021/06/12 15:18:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		store_star_flag(va_list ap, t_tag *tag)
{
	if (tag->precision == -1)
	{
		tag->width = va_arg(ap, int);
		if (tag->width < 0)
		{
			tag->minus = 1;
			tag->width *= -1;
		}
	}
	else if (tag->precision == 0)
	{
		if ((tag->precision = va_arg(ap, int)) < 0)
			tag->precision = -1;
	}
	else
		tag->width = va_arg(ap, int);
}

int			add_space(int buf_len, t_tag *tag, char **buf)
{
	if (buf_len >= tag->width)
	{
		if (!(*buf = ft_strjoin(" ", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else
		*buf[0] = ' ';
	return (0);
}
