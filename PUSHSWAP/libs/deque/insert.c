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

int	insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *frontNode;
	
	if (!pDeque)
		return FALSE;
	frontNode = (DequeNode *)calloc(1, sizeof(DequeNode));
	if (!frontNode)
		return FALSE;
	*frontNode = element;

    if (isLinkedDequeEmpty(pDeque))
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

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *rearNode;
	
	if (!pDeque)
		return FALSE;
	rearNode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!rearNode)
		return FALSE;
	*rearNode = element;
	
	if (isLinkedDequeEmpty(pDeque))
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
