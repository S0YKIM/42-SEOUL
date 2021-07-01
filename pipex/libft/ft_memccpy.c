/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:26:38 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 20:59:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int value, size_t num)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	unsigned char	c;
	size_t			i;

	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	c = (unsigned char)value;
	i = 0;
	while (num--)
	{
		new_dest[i] = new_src[i];
		if (new_src[i] == c)
			return (dest + i + 1);
		++i;
	}
	return (0);
}
