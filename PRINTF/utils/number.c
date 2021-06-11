/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:42:42 by sokim             #+#    #+#             */
/*   Updated: 2021/06/09 16:23:17 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	abs_nbr(unsigned long long nbr, t_tag *tag)
{
	if ((tag->type == 'd' || tag->type == 'i') && (int)nbr < 0)
	{
		tag->nbr_sign = -1;
		nbr = -nbr;
	}
	return (nbr);
}

int					add_pointer_prefix(t_tag *tag, char **buf)
{
	if (tag->type == 'p')
	{
		if (!(*buf = ft_strjoin("0x", *buf, 'R')))
			return (ERROR);
		return (2);
	}
	return (0);
}

int					count_len_of_number(unsigned long long nbr, t_tag *tag)
{
	int		cnt;

	if (!nbr && tag->precision)
		return (1);
	cnt = 0;
	while (nbr)
	{
		nbr /= tag->nbr_base;
		++cnt;
	}
	return (cnt);
}
