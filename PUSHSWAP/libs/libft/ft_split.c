/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:13:39 by sokim             #+#    #+#             */
/*   Updated: 2022/02/27 16:11:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static char	**ft_malloc_error(char **tab)
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

char	**ft_split(char const *s, char c)
{
	char		**tab;
	char const	*start;
	size_t		index;

	tab = (char **)malloc(sizeof(char *) * (ft_number_of_words(s, c) + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				++s;
			tab[index] = (char *)malloc(sizeof(char) * (s - start + 1));
			if (!tab[index])
				return (ft_malloc_error(tab));
			ft_strlcpy(tab[index++], start, s - start + 1);
		}
		else
			++s;
	}
	tab[index] = NULL;
	return (tab);
}
