/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:13:39 by sokim             #+#    #+#             */
/*   Updated: 2021/07/01 22:19:14 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

char			**get_awk(char const *s)
{
	char		**tab;
	int			i;
	int			j;
	int			cnt;

	if (!(tab = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	tab[0] = ft_strdup("awk");
	cnt = 0;
	i = 3;
	while (s[++i])
		if ((s[i] != '\'') && (s[i] != '\\') && (s[i] != '\"'))
			++cnt;
	tab[1] = (char *)malloc(sizeof(char) * (cnt + 1));
	i = 3;
	j = 0;
	while (s[++i])
	{
		if ((s[i] != '\'') && (s[i] != '\\') && (s[i] != '\"'))
			tab[1][j++] = s[i];
	}
	tab[1][j] = 0;
	tab[2] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	char const	*start;
	size_t		index;

	if (!s)
		return (NULL);
	if (ft_strncmp("awk", s, 3) == 0)
		return (get_awk(s));
	tab = (char **)malloc(sizeof(char *) *
					(ft_number_of_words(s, c) + 1));
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
