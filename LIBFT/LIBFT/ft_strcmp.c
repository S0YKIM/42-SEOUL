/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:12:58 by sokim             #+#    #+#             */
/*   Updated: 2022/01/15 17:13:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size < (dest_len + 1))
		return (size + src_len);
	if (size > (dest_len + 1))
	{
		while (src[i] && (dest_len + 1 + i < size))
		{
			dest[dest_len + i] = src[i];
			++i;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
