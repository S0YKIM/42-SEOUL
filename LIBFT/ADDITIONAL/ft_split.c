/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:13:39 by sokim             #+#    #+#             */
/*   Updated: 2021/05/18 18:35:19 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_error(char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_number_of_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	if (!s[0])
		return (0);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++cnt;
			while (s[i] && s[i] != c)
				++i;
			--i;
		}
		++i;
	}
	return (cnt);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	char const	*start;
	size_t		index;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) *
					(ft_number_of_words(s, c) + 1))))
		return (NULL);
	index = 0;
	while (*s)
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				++s;
			if (!(tab[index] = (char *)malloc(sizeof(char) * (s - start + 1))))
				return (ft_malloc_error(tab));
			ft_strlcpy(tab[index++], start, s - start + 1);
		}
		else
			++s;
	tab[index] = 0;
	return (tab);
}
