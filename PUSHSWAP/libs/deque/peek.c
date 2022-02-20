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

DequeNode*	peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode *frontNode;
	
	if (!pDeque)
		return NULL;
	frontNode = pDeque->pFrontNode;
	return (frontNode);
}

DequeNode*	peekRearLD(LinkedDeque* pDeque)
{
  DequeNode *rearNode;

  if (!pDeque)
    return NULL;
  rearNode = pDeque->pRearNode;
  return (rearNode);
}
