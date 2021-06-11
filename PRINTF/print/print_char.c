/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:57:17 by sokim             #+#    #+#             */
/*   Updated: 2021/06/04 21:03:48 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_width(int width, int zero)
{
	int		result;

	result = 0;
	while (width-- > 1)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		++result;
	}
	return (result);
}

int			print_char(int c, t_tag *tag)
{
	int		result;

	result = 0;
	if (tag->minus == 1)
		result += ft_putchar(c);
	result += print_width(tag->width, tag->zero);
	if (tag->minus == 0)
		result += ft_putchar(c);
	return (result);
}
