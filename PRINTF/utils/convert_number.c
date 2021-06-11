/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:39:03 by sokim             #+#    #+#             */
/*   Updated: 2021/06/08 17:42:36 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_nbr_base(t_tag *tag)
{
	if (tag->type == 'x' || tag->type == 'X' || tag->type == 'p')
		tag->nbr_base = 16;
	else if (tag->type == 'o')
		tag->nbr_base = 8;
}

static char	*set_base_of_number(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	else if (type == 'o')
		return ("01234567");
	return (NULL);
}

char		convert_number_to_base(unsigned long long nbr, t_tag *tag)
{
	char	result;
	char	*base;

	base = set_base_of_number(tag->type);
	if (!base)
		return ('\0');
	result = base[nbr % tag->nbr_base];
	return (result);
}
