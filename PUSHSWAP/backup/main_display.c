/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:57:33 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:57:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

// 평가 시에 삭제
static void	displayDeque(t_deque *pDeque)
{
	t_node	*curr;
	int		i;

	if (!pDeque)
		return ;
	curr = pDeque->pFrontNode;
	i = 0;
	while (curr)
	{
		printf("Current element count[%i]: %d\n", i,
			pDeque->currentElementCount);
		printf("Number: %d\n", curr->num);
		printf("Index: %d\n", curr->index);
		printf("Binary number: %s\n", curr->binary);
		curr = curr->pRLink;
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	create_deque_with_arguments(argc, argv, &data);
	if (data.a->currentElementCount <= 3)
		sort_three(&data);
	else if (data.a->currentElementCount <= 5)
		sort_five(&data);
	else
		sort_many(&data);
	displayDeque(data.a);
	displayDeque(data.b);
	return (0);
}
