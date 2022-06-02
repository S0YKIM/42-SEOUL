/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:43:22 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 13:50:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long 		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	print_philo(t_philo *philo, long long time, char *msg)
{
	printf("%lld ", time - philo->table->start_time);
	printf("%i ", philo->id);
	printf("%s\n", msg);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\r' ||
		c == '\f' || c == '\v' ||
		c == '\n' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str && is_space(str[i]))
		++i;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		num *= 10;
		num += str[i] - '0';
		++i;
	}
	if (sign * num > MAX_INT || sign * num < MIN_INT)
		return (ERROR);
	return (sign * num);
}
