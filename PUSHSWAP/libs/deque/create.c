/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:14:07 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:14:07 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*createDeque(void)
{
	t_deque	*myDeque;

	myDeque = (t_deque *)malloc(sizeof(t_deque));
	if (!myDeque)
		return (FALSE);
	myDeque->currentElementCount = 0;
	myDeque->pFrontNode = NULL;
	myDeque->pRearNode = NULL;
	return (myDeque);
}
