/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:54:05 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 00:54:05 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	long long	r;
	int			sign;

	r = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * sign);
}
