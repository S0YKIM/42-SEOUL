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

static void	add_integers_into_tmp(char **input, t_deque **tmp)
{
	int		i;
	int		result;
	t_node	node;

	i = 0;
	while (input[i])
	{
		node.num = ft_atoi(input[i]);
		result = insertRearLD(*tmp, node);
		if (!result)
			exit_with_memory_free("Failed to insert node.", *tmp, NULL, input);
		i++;
	}
}

static int	insert_numbers_into_tmp(int argc, char **argv, t_deque **tmp)
{
	char	**input;
	int		result;
	int		i;

	i = 0;
	while (++i < argc)
	{
		input = parse_argument_by_space(argv[i]);
		if (!input)
			exit_with_memory_free("Failed to parse arguments.", *tmp, NULL, NULL);
		result = check_validate_integer(input);
		if (!result)
			exit_with_memory_free("Not a valid integer.", *tmp, NULL, input);
		add_integers_into_tmp(input, tmp);
		free_double_char(input);
	}
	return (FT_TRUE);
}

t_deque	*create_deque_with_arguments(int argc, char **argv)
{
	//t_deque	*a;
	t_deque *tmp;
	int		result;

	tmp = createDeque();
	if (!tmp)
		return NULL;
	insert_numbers_into_tmp(argc, argv, &tmp);
	result = check_duplicates(tmp);
	if (result)
		exit_with_memory_free("Numbers duplicated.", tmp, NULL, NULL);
	result = check_deque_sorted(tmp);
	if (result)
		exit_with_memory_free("Numbers already sorted.", tmp, NULL, NULL);
	return (tmp);
	//return (a);
}
