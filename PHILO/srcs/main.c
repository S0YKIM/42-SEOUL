/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:08 by sokim             #+#    #+#             */
/*   Updated: 2022/04/02 18:33:44 by sokim            ###   ########.fr       */
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

	if (check_arguments(argc, argv) == ERROR)
		return (print_error("Invalid arguments."));
	if (init(argv, &table) == ERROR)
		return (print_error("Failed to initialize."));
	return (EXIT_SUCCESS);
}