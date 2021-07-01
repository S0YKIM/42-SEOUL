/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:46:23 by sokim             #+#    #+#             */
/*   Updated: 2021/05/14 20:48:39 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t num)
{
	unsigned char	*new_ptr;

	new_ptr = (unsigned char *)ptr;
	while (num--)
		*new_ptr++ = 0;
	return (ptr);
}
