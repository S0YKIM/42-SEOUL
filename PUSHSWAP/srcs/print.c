/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:29:09 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 20:29:09 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_node_a(t_node *node)
{
	int		i;
	char	*tmp;

	tmp = ft_itoa(node->num);
	i = 20 - ft_strlen(tmp);
	while (i--)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(tmp, 1);
	free(tmp);
}

void	print_deque_ab(t_deque *a, t_deque *b)
{
	t_node	*node_a;
	t_node	*node_b;

	ft_putendl_fd("             STACK_A : STACK_B", 1);
	node_a = peekFrontLD(a);
	node_b = peekFrontLD(b);
	while (node_a || node_b)
	{
		if (node_a)
		{
			print_node_a(node_a);
			node_a = node_a->pRLink;
		}
		else
			ft_putstr_fd("                    ", 1);
		ft_putstr_fd(" : ", 1);
		if (node_b)
		{
			ft_putnbr_fd(node_b->num, 1);
			node_b = node_b->pRLink;
		}
		ft_putchar_fd('\n', 1);
	}
}
