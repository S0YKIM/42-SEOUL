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

# define TRUE		1
# define FALSE		0

# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				index;
	char			*binary;
	struct s_node	*pRLink;
	struct s_node	*pLLink;
}	t_node;

typedef struct s_deque
{
	int		currentElementCount;
	t_node	*pFrontNode;
	t_node	*pRearNode;
}	t_deque;

typedef struct s_push_swap
{
	t_deque	*a;
	t_deque	*b;
}	t_push_swap;

t_deque	*createDeque(void);
int		insertFrontLD(t_deque *pDeque, t_node element);
int		insertRearLD(t_deque *pDeque, t_node element);
t_node	*deleteFrontLD(t_deque *pDeque);
t_node	*deleteRearLD(t_deque *pDeque);
t_node	*peekFrontLD(t_deque *pDeque);
t_node	*peekRearLD(t_deque *pDeque);
void	deleteDeque(t_deque **pDeque);
int		isDequeEmpty(t_deque *pDeque);

#endif
