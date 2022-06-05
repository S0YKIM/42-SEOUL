/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:08 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 14:16:03 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	print_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!is_valid_arguments(argc, argv))
		return (print_error("Invalid arguments."));
	if (!init(argc, argv, &table))
		return (print_error("Failed to initialize."));
	if (!start_dining(&table))
		return (print_error("Failed to create philo threads."));
	end_dining(&table);
	return (EXIT_SUCCESS);
}
