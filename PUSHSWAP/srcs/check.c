/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:09:29 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 00:09:29 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (!ft_isdigit(str[i]))
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

static int	check_int_range(char *str)
{
	if (ft_atol(str) < FT_INT_MIN || ft_atol(str) > FT_INT_MAX)
		return (FT_FALSE);
	return (FT_TRUE);
}

int	check_validate_integer(char **str)
{
	int	i;
	int	result;

	if (!str)
		return (FT_FALSE);
	i = 0;
	while (str[i])
	{
		result = check_integer(str[i]);
		if (!result)
			return (FT_FALSE);
		result = check_int_range(str[i]);
		if (!result)
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

int	check_duplicates(t_deque *deque)
{
	t_node	*curr;
	t_node	*tmp;

	if (deque->currentElementCount == 1)
		return (FT_FALSE);
	curr = deque->pFrontNode;
	while (curr->pRLink)
	{
		tmp = curr->pRLink;
		while (tmp)
		{
			if (curr->num == tmp->num)
				return (FT_TRUE);
			tmp = tmp->pRLink;
		}
		curr = curr->pRLink;
	}
	return (FT_FALSE);
}

int	check_deque_sorted(t_deque *deque)
{
	t_node	*curr;

	if (deque->currentElementCount == 1)
		return (FT_TRUE);
	curr = deque->pFrontNode;
	while (curr->pRLink)
	{
		if (curr->num > curr->pRLink->num)
			return (FT_FALSE);
		curr = curr->pRLink;
	}
	return (FT_TRUE);
}
