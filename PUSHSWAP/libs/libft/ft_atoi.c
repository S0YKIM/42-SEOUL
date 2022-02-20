/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:38:49 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:37:47 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\r'
		|| c == '\f' || c == '\v'
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		i;
	int		sign;

	i = 0;
	while (str && is_space(str[i]))
		++i;
	sign = 1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	ret = 0;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		ret *= 10;
		ret += str[i] - '0';
		++i;
	}
	return (sign * ret);
}
