/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:52:05 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 22:52:05 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minimum_number(t_deque *deque)
{
	int		num;
	t_node	*curr;

	curr = deque->pFrontNode;
	num = curr->num;
	while (curr->pRLink)
	{
		if (curr->pRLink->num < num)
			num = curr->pRLink->num;
		curr = curr->pRLink;
	}
	return (num);
}

int	get_maximum_number(t_deque *deque)
{
	int		num;
	t_node	*curr;

	curr = deque->pFrontNode;
	num = curr->num;
	while (curr->pRLink)
	{
		if (curr->pRLink->num > num)
			num = curr->pRLink->num;
		curr = curr->pRLink;
	}
	return (num);
}
