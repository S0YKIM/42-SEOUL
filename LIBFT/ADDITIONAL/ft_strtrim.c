/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:32:18 by sokim             #+#    #+#             */
/*   Updated: 2021/12/16 16:56:51 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		++i;
	}
	return (i);
}

static int	ft_get_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			break ;
		++i;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	ret = (char *)malloc(end - start + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start + 1);
	return (ret);
}
