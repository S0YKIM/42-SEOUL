/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:36:25 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 21:26:38 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int value)
{
	unsigned char	find;
	int				i;

	find = (unsigned char);
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == find)
			return ((char *)str + i);
		--i;
	}
	if (str[i] == find)
		return ((char *)str);
	return (NULL);
}
