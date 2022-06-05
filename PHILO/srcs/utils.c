/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:43:22 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 13:57:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ph_print(t_philo *philo, long long time, char *msg)
{
	if (check_exit(philo))
		return ;
	pthread_mutex_lock(philo->table->print);
	printf("%lld ", time - philo->table->start_time);
	printf("%i ", philo->id);
	printf("%s\n", msg);
	pthread_mutex_unlock(philo->table->print);
}

void	ph_usleep(t_table *table, long long time)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!table-> exit)
	{
		now = get_time();
		if (now - start >= time)
			break ;
		usleep(10);
	}
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\r' \
	|| c == '\f' || c == '\v' \
	|| c == '\n' || c == ' ')
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
