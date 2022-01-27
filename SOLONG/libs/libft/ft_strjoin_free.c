/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:40:36 by sokim             #+#    #+#             */
/*   Updated: 2022/01/26 22:02:09 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char *s1, char *s2, char c)
{
	if (c == 'B')
	{
		free(s1);
		free(s2);
	}
	else if (c == 'L')
		free(s1);
	else if (c == 'R')
		free(s2);
}

static char	*ft_check_empty(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
	{
		tmp = ft_strdup(s2);
		free(s2);
		return (tmp);
	}
	else if (s1 && !s2)
	{
		tmp = ft_strdup(s1);
		free(s1);
		return (tmp);
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2, char c)
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
	ft_free(s1, s2, c);
	return (line);
}
