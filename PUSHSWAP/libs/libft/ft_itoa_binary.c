/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:59:54 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 02:59:54 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_reverse_array(int num)
{
	char	binary[32];
	char	*result;
	int		i;

	i = 0;
	while (i < 32)
	{
		binary[i] = (num % 2) + '0';
		num = num / 2;
		i++;
		if (num == 0)
			break ;
	}
	binary[i++] = '\0';
	result = ft_strdup(binary);
	return (result);
}

char	*ft_itoa_binary(int num)
{
	char	*tmp;
	char	*result;
	int		len;
	int		i;

	tmp = make_reverse_array(num);
	len = ft_strlen(tmp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (len--)
	{
		result[i] = tmp[len];
		i++;
	}
	result[i++] = '\0';
	return (result);
}
