/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:46:01 by sokim             #+#    #+#             */
/*   Updated: 2022/02/27 21:10:23 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_integers_into_deque(char **input, t_deque *deque)
{
	int		i;
	int		result;
	t_node	node;

	i = 0;
	while (input[i])
	{
		node.num = ft_atoi(input[i]);
		result = insertRearLD(deque, node);
		if (!result)
			exit_with_memory_free("Failed to insert node.", deque, NULL, input);
		i++;
	}
}

static int	insert_numbers_into_deque(int argc, char **argv, t_deque *deque)
{
	char	**input;
	int		result;
	int		i;

	i = 0;
	while (++i < argc)
	{
		input = ft_split(argv[i], ' ');
		if (!input)
			exit_with_memory_free("Failed to parse arguments.",
				deque, NULL, NULL);
		if (!input[0])
			exit_with_memory_free("Error", deque, NULL, input);
		result = check_validate_integer(input);
		if (!result)
			exit_with_memory_free("Error", deque, NULL, input);
		add_integers_into_deque(input, deque);
		free_double_char(input);
	}
	return (FT_TRUE);
}

void	create_deque_with_arguments(int argc, char **argv, t_push_swap *data)
{
	int		result;

	data->a = createDeque();
	if (!data->a)
		exit_with_error_message("Failed to create deque A.");
	insert_numbers_into_deque(argc, argv, data->a);
	result = check_duplicates(data->a);
	if (result)
		exit_with_memory_free("Error", data->a, NULL, NULL);
	result = check_deque_sorted(data->a);
	if (result)
		exit_with_memory_free(NULL, data->a, NULL, NULL);
	data->b = createDeque();
	if (!data->b)
		exit_with_memory_free("Failed to create deque B.", data->a, NULL, NULL);
}
