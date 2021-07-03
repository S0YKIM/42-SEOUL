/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:35:39 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 20:51:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int value, size_t num)
{
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *)s;
	c = (unsigned char)value;
	while (num--)
	{
		if (*str == c)
			return (str);
		++str;
	}
	return (NULL);
}
