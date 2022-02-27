/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:57:33 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 22:57:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	create_deque_with_arguments(argc, argv, &data);
	if (data.a->currentElementCount <= 3)
		sort_three(&data);
	else if (data.a->currentElementCount <= 5)
		sort_five(&data);
	else
		sort_many(&data);
	free_all(&data);
	return (0);
}
