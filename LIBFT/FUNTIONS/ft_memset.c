/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:47:40 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 20:48:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*temp_ptr;
	unsigned char	c;

	c = (unsigned char)value;
	temp_ptr = (unsigned char *)ptr;
	while (num--)
		*temp_ptr++ = c;
	return (ptr);
}
