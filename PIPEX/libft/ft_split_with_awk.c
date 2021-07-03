/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_awk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:13:39 by sokim             #+#    #+#             */
/*   Updated: 2021/07/03 21:23:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_valid(char const *s)
{
	int		i;
	int		len;
	int		flag;

	i = 0;
	len = ft_strlen(s);
	flag = -1;
	if ((s[i] == '\'') && (s[len - i - 1] == '\''))
		flag = 1;
	else if ((s[i] == '\"') && (s[len - i - 1] == '\"'))
		flag = 1;
	return (flag);
}

static char	*fill_tab_one(int len, char const *s)
{
	char	*str;
	int		new_len;
	int		i;
	int		j;

	new_len = len - 2;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < new_len)
	{
		str[j] = s[i];
		++j;
	}
	str[++j] = '\0';
	return (str);
}

char	**ft_split_with_awk(char const *s)
{
	char		**tab;
	int			flag;
	int			len;

	flag = check_valid(s + 4);
	if (flag == -1)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * 3);
	if (!tab)
		return (NULL);
	tab[0] = ft_strdup("awk");
	if (!tab[0])
		ft_malloc_error(tab);
	len = ft_strlen(s + 4);
	tab[1] = fill_tab_one(len, s + 4);
	if (!tab[1])
		ft_malloc_error(tab);
	tab[2] = NULL;
	return (tab);
}
