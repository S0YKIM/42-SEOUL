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
	// t_list	*item;
	// t_list	*item_next;
	// int		i;

	// item = deque->top;
	// while (item)
	// {
	// 	item_next = item->next;
	// 	i = 0;
	// 	while (item_next)
	// 	{
	// 		if (item_value(item) == item_value(item_next))
	// 			return (FT_FALSE);
	// 		item_next = item_next->next;
	// 		i++;
	// 	}
	// 	item = item->next;
	// }
	// return (FT_TRUE);
	if (!deque)
		return (0);
	return (0);
}

int	check_deque_sorted(t_deque *deque)
{
	// t_list	*tmp;

	// tmp = deque->top;
	// while (tmp->next)
	// {
	// 	if (item_value(tmp) > item_value(tmp->next))
	// 		return (FT_FALSE);
	// 	tmp = tmp->next;
	// }
	// return (FT_TRUE);
	if (!deque)
		return (0);
	return (0);
}