/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:41:24 by sokim             #+#    #+#             */
/*   Updated: 2021/05/20 19:14:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++len;
		++s;
	}
	return (len);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (src_len);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(*s1) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, sizeof(*s1) * (s1_len + 1));
	ft_strlcat(ret, (char *)s2, sizeof(*s2) * (s1_len + s2_len + 1));
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = 0;
	return (str);
}
