/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:17:22 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:17:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_node	*deleteFrontLD(t_deque *pDeque)
{
	t_node	*delNode;

	if (!pDeque)
		return (NULL);
	if (isDequeEmpty(pDeque))
		return (NULL);
	delNode = pDeque->pFrontNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pFrontNode = delNode->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
	}
	pDeque->currentElementCount--;
	return (delNode);
}

t_node	*deleteRearLD(t_deque *pDeque)
{
	t_node	*delNode;

	if (!pDeque)
		return (NULL);
	if (isDequeEmpty(pDeque))
		return (NULL);
	delNode = pDeque->pRearNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pRearNode = delNode->pLLink;
		pDeque->pRearNode->pRLink = NULL;
	}
	pDeque->currentElementCount--;
	return (delNode);
}

void	deleteDeque(t_deque **pDeque)
{
	t_node	*curr;	
	t_node	*temp;

	if (!pDeque || !(*pDeque))
		return ;
	curr = (*pDeque)->pFrontNode;
	while (curr)
	{
		temp = curr;
		curr = curr->pRLink;
		free(temp);
		temp = NULL;
	}
	free(*pDeque);
	*pDeque = NULL;
}
