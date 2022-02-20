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

DequeNode*	deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *delNode;
	
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
		return NULL;

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

DequeNode*	deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *delNode;
	
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
		return NULL;

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
