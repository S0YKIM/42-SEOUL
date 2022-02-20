/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:21:53 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 20:21:53 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef struct				DequeNodeType
{
	int						data;
	struct DequeNodeType*	pRLink;
	struct DequeNodeType*	pLLink;
}							DequeNode;

typedef struct	LinkedDequeType
{
	int			currentElementCount;
	DequeNode*	pFrontNode;
	DequeNode*	pRearNode;
}				LinkedDeque;

LinkedDeque		*createLinkedDeque();
int				insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int				insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode*		deleteFrontLD(LinkedDeque* pDeque);
DequeNode*		deleteRearLD(LinkedDeque* pDeque);
DequeNode*		peekFrontLD(LinkedDeque* pDeque);
DequeNode*		peekRearLD(LinkedDeque* pDeque);
void			deleteLinkedDeque(LinkedDeque** pDeque);
int				isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
# define _COMMON_QUEUE_DEF_

# define TRUE		1
# define FALSE		0

#endif