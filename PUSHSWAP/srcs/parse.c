/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:46:01 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 23:46:01 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_argument_by_space(char *argument)
{
	char	**input;

	input = ft_split(argument, ' ');
	if (!input)
		return NULL;
	return (input);
}

static void	add_integers_into_deque(char **input, t_deque **deque)
{
	int		i;
	int		result;
	t_node	node;

	i = 0;
	while (input[i])
	{
		node.num = ft_atoi(input[i]);
		result = insertRearLD(*deque, node);
		if (!result)
			exit_with_memory_free("Failed to insert node.", *deque, NULL, input);
		i++;
	}
}

static int	insert_numbers_into_deque(int argc, char **argv, t_deque **deque)
{
	char	**input;
	int		result;
	int		i;

	i = 0;
	while (++i < argc)
	{
		input = parse_argument_by_space(argv[i]);
		if (!input)
			exit_with_memory_free("Failed to parse arguments.", *deque, NULL, NULL);
		result = check_validate_integer(input);
		if (!result)
			exit_with_memory_free("Not a valid integer.", *deque, NULL, input);
		add_integers_into_deque(input, deque);
		free_double_char(input);
	}
	return (FT_TRUE);
}

t_deque	*create_deque_with_arguments(int argc, char **argv)
{
	t_deque *deque;
	int		result;

	deque = createDeque();
	if (!deque)
		return NULL;
	insert_numbers_into_deque(argc, argv, &deque);
	result = check_duplicates(deque);
	if (result)
		exit_with_memory_free("Numbers duplicated.", deque, NULL, NULL);
	result = check_deque_sorted(deque);
	if (result)
		exit_with_memory_free("Numbers already sorted.", deque, NULL, NULL);
	return (deque);
}
