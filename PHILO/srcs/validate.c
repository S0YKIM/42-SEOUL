/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:19 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 14:30:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	is_validate_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_num(argv[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	is_valid_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (!is_validate_num(argc, argv))
		return (FALSE);
	return (TRUE);
}
