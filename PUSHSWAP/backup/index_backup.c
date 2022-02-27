/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 03:20:11 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 03:20:11 by sokim            ###   ########.fr       */
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

static void	change_raw_data_into_index(t_push_swap *data)
{
	int		current;
	int		index;
	t_node	*i;
	t_node	*j;
	t_node	element;

	i = data->tmp->pFrontNode;
	while (i)
	{
		index = 0;
		current = i->num;
		j = data->tmp->pFrontNode;
		while (j)
		{
			if (current > j->num)
				index++;
			j = j->pRLink;
		}
		element.num = index;
		element.binary = NULL;
		insertRearLD(data->a, element);
		i = i->pRLink;
	}
}

void	create_deque_a(t_push_swap *data)
{
	int		max_digit;
	t_node	*curr;

	change_raw_data_into_index(data);
	max_digit = get_max_digit(data->a->currentElementCount);
	curr = data->a->pFrontNode;
	while (curr)
	{
		curr->binary = change_index_into_binary(curr->num, max_digit);
		curr = curr->pRLink;
	}
}
