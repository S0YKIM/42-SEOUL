/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:12:51 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 14:26:49 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_starve(t_philo *philo, t_table *table)
{
	if (get_time() - philo->last_eat_time >= table->time_to_die)
	{
		table->exit = TRUE;
		pthread_mutex_lock(philo->table->print);
		printf("%lld ", get_time() - philo->table->start_time);
		printf("%i ", philo->id);
		printf("%s\n", "died");
		pthread_mutex_unlock(philo->table->print);
		return (TRUE);
	}
	return (FALSE);
}

static int	check_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		if (table->num_of_must_eat > table->philo[i].eat_cnt)
			return (FALSE);
		i++;
	}
	table->exit = TRUE;
	return (TRUE);
}

int	check_exit(t_philo *philo)
{
	pthread_mutex_lock(philo->table->monitor);
	if (philo->table->exit)
	{
		pthread_mutex_unlock(philo->table->monitor);
		return (TRUE);
	}
	if (check_starve(philo, philo->table))
	{
		pthread_mutex_unlock(philo->table->monitor);
		return (TRUE);
	}
	if (philo->table->num_of_must_eat != 0 && check_full(philo->table))
	{
		pthread_mutex_unlock(philo->table->monitor);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->table->monitor);
	return (FALSE);
}
