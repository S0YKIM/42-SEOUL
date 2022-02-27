/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:50:35 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 20:50:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*change_index_into_binary(int num, int max_digit)
{
	char	*result;
	char	*binary;
	int		len;
	int		i;
	char	fill[32];

	binary = ft_itoa_binary(num);
	len = ft_strlen(binary);
	i = 0;
	while (len < max_digit)
	{
		fill[i] = '0';
		len++;
		i++;
	}
	fill[i] = '\0';
	if (fill[0])
	{
		result = ft_strjoin(fill, binary);
		free(binary);
	}
	else
		result = binary;
	return (result);
}

static int	get_max_digit(int cnt)
{
	int		num;
	char	*str;

	str = ft_itoa_binary(cnt - 1);
	num = ft_strlen(str);
	return (num);
}

static void	change_raw_data_into_index(t_deque *deque)
{
	int		current;
	t_node	*i;
	t_node	*j;

	i = deque->pFrontNode;
	while (i)
	{
		i->index = 0;
		current = i->num;
		j = deque->pFrontNode;
		while (j)
		{
			if (current > j->num)
				i->index++;
			j = j->pRLink;
		}
		i = i->pRLink;
	}
}

void	add_index_and_binary(t_deque *deque)
{
	int		max_digit;
	t_node	*curr;

	change_raw_data_into_index(deque);
	max_digit = get_max_digit(deque->currentElementCount);
	curr = deque->pFrontNode;
	while (curr)
	{
		curr->binary = change_index_into_binary(curr->index, max_digit);
		curr = curr->pRLink;
	}
}
