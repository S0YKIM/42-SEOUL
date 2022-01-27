/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:40:36 by sokim             #+#    #+#             */
/*   Updated: 2022/01/27 13:56:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check_empty(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	else if (s1 && !s2)
		return (s1);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (ft_check_empty(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	line = (char *)malloc(sizeof(*s1) * (s1_len + s2_len + 1));
	if (line)
	{
		ft_strlcpy(line, s1, sizeof(*s1) * (s1_len + 1));
		ft_strlcat(line, s2, sizeof(*s2) * (s1_len + s2_len + 1));
	}
	return (line);
}
