/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:15:21 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:15:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	isDequeEmpty(t_deque *pDeque)
{
	if (!pDeque)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
