/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:40:36 by sokim             #+#    #+#             */
/*   Updated: 2022/01/17 17:51:38 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(*s1) * (s1_len + s2_len + 1));
	if (ret)
	{
		ft_strlcpy(ret, s1, sizeof(*s1) * (s1_len + 1));
		free(s1);
		ft_strlcat(ret, s2, sizeof(*s2) * (s1_len + s2_len + 1));
	}
	return (ret);
}
