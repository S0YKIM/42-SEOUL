/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:45:21 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 19:45:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_deque *deque)
{
	t_node	*firstnode;
	t_node	*secondnode;

	firstnode = deleteFrontLD(deque);
	secondnode = deleteFrontLD(deque);
	insertFrontLD(deque, *firstnode);
	insertFrontLD(deque, *secondnode);
	free(firstnode);
	free(secondnode);
}

static void	push(t_deque *from, t_deque *to)
{
	t_node	*pushnode;

	pushnode = deleteFrontLD(from);
	insertFrontLD(to, *pushnode);
	free(pushnode);
}

static void	rotate(t_deque *deque)
{
	t_node	*frontnode;

	frontnode = deleteFrontLD(deque);
	insertRearLD(deque, *frontnode);
	free(frontnode);
}

static void	rrotate(t_deque *deque)
{
	t_node	*lastnode;

	lastnode = deleteRearLD(deque);
	insertFrontLD(deque, *lastnode);
	free(lastnode);
}

int	operator(char *op, t_push_swap *data)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		swap(data->a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		swap(data->b);
	if (!ft_strcmp(op, "pa"))
		push(data->b, data->a);
	if (!ft_strcmp(op, "pb"))
		push(data->a, data->b);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		rotate(data->a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		rotate(data->b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		rrotate(data->a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		rrotate(data->b);
	ft_putendl_fd(op, 1);
	return (FT_TRUE);
}
