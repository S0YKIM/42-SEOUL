/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:15:34 by sokim             #+#    #+#             */
/*   Updated: 2021/06/09 18:21:46 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		store_star_flag(va_list ap, char *format, t_tag *tag, int i)
{
	if (format[i] == '*')
	{
		tag->star = 1;
		if (tag->precision == -1)
		{
			tag->width = va_arg(ap, int);
			if (tag->width < 0)
			{
				tag->minus = 1;
				tag->width *= -1;
			}
		}
		else
		{
			if ((tag->precision = va_arg(ap, int)) < 0)
				tag->precision = -1;
		}
	}
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
