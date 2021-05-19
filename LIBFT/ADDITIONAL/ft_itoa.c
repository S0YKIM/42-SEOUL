/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:06:05 by sokim             #+#    #+#             */
/*   Updated: 2021/05/10 21:44:53 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_abs(long long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int				ft_int_len(int n)
{
	int		len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	char			*ret;
	int				len;
	int				sign;
	long long int	nbr;

	sign = (n < 0) ? -1 : 1;
	len = ft_int_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	nbr = ft_abs(n);
	ret[len] = 0;
	while (len--)
	{
		ret[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
