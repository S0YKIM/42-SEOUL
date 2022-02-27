/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:18:08 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:18:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_node	*peekFrontLD(t_deque *pDeque)
{
	t_node	*frontNode;

	if (!pDeque)
		return (NULL);
	frontNode = pDeque->pFrontNode;
	return (frontNode);
}

t_node	*peekRearLD(t_deque *pDeque)
{
	t_node	*rearNode;

	if (!pDeque)
		return (NULL);
	rearNode = pDeque->pRearNode;
	return (rearNode);
}
