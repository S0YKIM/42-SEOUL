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
			{
				operator("pb", data);
				ft_putendl_fd("pb", 1);
			}
			else
			{
				operator("ra", data);
				ft_putendl_fd("ra", 1);
			}
		}
		while (!isDequeEmpty(data->b))
		{
			operator("pa", data);
			ft_putendl_fd("pa", 1);
		}
	}
}

void	sort_three(t_push_swap *data)
{
	add_index_and_binary(data->a);
	radix_sort(data);
}

void	sort_five(t_push_swap *data)
{
	add_index_and_binary(data->a);
	radix_sort(data);
}

void	sort_many(t_push_swap *data)
{
	add_index_and_binary(data->a);
	radix_sort(data);
}