/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:53:28 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 20:50:29 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == src || !num)
		return (dest);
	if (dest < src)
	{
		temp_dest = (unsigned char *)dest;
		temp_src = (unsigned char *)src;
		while (num--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_dest = (unsigned char *)dest + (num - 1);
		temp_src = (unsigned char *)src + (num - 1);
		while (num--)
			*temp_dest-- = *temp_src--;
	}
	return (dest);
}
