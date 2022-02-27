/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:16:23 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:16:23 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	insertFrontLD(t_deque *pDeque, t_node element)
{
	t_node	*frontNode;

	if (!pDeque)
		return (FALSE);
	frontNode = (t_node *)malloc(sizeof(t_node));
	if (!frontNode)
		return (FALSE);
	*frontNode = element;
	if (isDequeEmpty(pDeque))
	{
		pDeque->pRearNode = frontNode;
		frontNode->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode->pLLink = frontNode;
		frontNode->pRLink = pDeque->pFrontNode;
	}
	pDeque->pFrontNode = frontNode;
	frontNode->pLLink = NULL;
	pDeque->currentElementCount++;
	return (TRUE);
}

int	insertRearLD(t_deque *pDeque, t_node element)
{
	t_node	*rearNode;

	if (!pDeque)
		return (FALSE);
	rearNode = (t_node *)malloc(sizeof(t_node));
	if (!rearNode)
		return (FALSE);
	*rearNode = element;
	if (isDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = rearNode;
		rearNode->pLLink = NULL;
	}
	else
	{
		pDeque->pRearNode->pRLink = rearNode;
		rearNode->pLLink = pDeque->pRearNode;
	}
	pDeque->pRearNode = rearNode;
	rearNode->pRLink = NULL;
	pDeque->currentElementCount++;
	return (TRUE);
}
