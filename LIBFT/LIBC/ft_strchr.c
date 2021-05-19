/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:53:50 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 21:26:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	unsigned char	find;
	int				i;

	find = (unsigned char)value;
	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			return ((char *)str + i);
		++i;
	}
	if (str[i] == find)
		return ((char *)str + i);
	return (NULL);
}
