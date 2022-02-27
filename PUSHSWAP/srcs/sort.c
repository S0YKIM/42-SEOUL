/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:33:15 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 21:33:15 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_push_swap *data)
{
	t_node	*curr;
	int		len;
	int		i;
	int		j;

	curr = peekFrontLD(data->a);
	len = ft_strlen(curr->binary);
	i = len;
	while (i--)
	{
		j = data->a->currentElementCount;
		while (j--)
		{
			curr = peekFrontLD(data->a);
			if (curr->binary[i] == '0')
				operator("pb", data);
			else
				operator("ra", data);
		}
		while (!isDequeEmpty(data->b))
			operator("pa", data);
	}
}

int	sort_three(t_push_swap *data)
{
	int	min;
	int	max;
	int	cnt;

	cnt = data->a->currentElementCount;
	if (cnt == 2)
		return (operator("sa", data));
	min = get_minimum_number(data->a);
	max = get_maximum_number(data->a);
	if (check_deque_sorted(data->a))
		return (FT_TRUE);
	if (min == data->a->pFrontNode->num)
		return (operator("sa", data) && operator("ra", data));
	if (max == data->a->pRearNode->num)
		return (operator("sa", data));
	if (max == data->a->pFrontNode->num && min == data->a->pRearNode->num)
		return (operator("ra", data) && operator("sa", data));
	if (max == data->a->pFrontNode->num)
		return (operator("ra", data));
	if (min == data->a->pRearNode->num)
		return (operator("rra", data));
	return (FT_FALSE);
}

void	sort_five(t_push_swap *data)
{
	int	min;
	int	cnt;

	cnt = data->a->currentElementCount;
	while (cnt > 3)
	{
		min = get_minimum_number(data->a);
		while (min != data->a->pFrontNode->num)
		{
			if (min == data->a->pFrontNode->pRLink->num
				|| min == data->a->pFrontNode->pRLink->pRLink->num)
				operator("ra", data);
			else
				operator("rra", data);
		}
		if (check_deque_sorted(data->a) && isDequeEmpty(data->b))
			return ;
		operator("pb", data);
		cnt--;
	}
	sort_three(data);
	while (!isDequeEmpty(data->b))
		operator("pa", data);
}

void	sort_many(t_push_swap *data)
{
	add_index_and_binary(data->a);
	radix_sort(data);
}
