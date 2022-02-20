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

LinkedDeque*	createLinkedDeque()
{
	LinkedDeque	*myDeque;

	myDeque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
	if (!myDeque)
		return FALSE;
	return (myDeque);
}
