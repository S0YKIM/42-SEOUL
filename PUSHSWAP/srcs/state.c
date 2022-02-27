/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:01:53 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 23:01:53 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_push_swap *data)
{
	if (!data)
		return ;
	if (data->a)
		deleteDeque(&data->a);
	if (data->b)
		deleteDeque(&data->b);
}

void	free_double_char(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_with_error_message(char *msg)
{
	ft_putstr_fd(msg, 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exit_with_memory_free(char *msg, t_deque *a, t_deque *b, char **str)
{
	if (msg)
	{
		ft_putstr_fd(msg, 1);
		write(1, "\n", 1);
	}
	if (a)
		deleteDeque(&a);
	if (b)
		deleteDeque(&b);
	if (str)
		free(str);
	exit(EXIT_FAILURE);
}
