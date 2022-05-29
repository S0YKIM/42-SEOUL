/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:08 by sokim             #+#    #+#             */
/*   Updated: 2022/05/29 22:16:32 by sokim            ###   ########.fr       */
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

	if (is_valid_arguments(argc, argv) == ERROR)
		return (print_error("Invalid arguments."));
	if (init(argv, &table) == ERROR)
		return (print_error("Failed to initialize."));
	return (EXIT_SUCCESS);
}
