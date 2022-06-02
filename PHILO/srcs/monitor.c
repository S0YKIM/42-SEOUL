/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:12:51 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 16:34:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_starve(t_philo *philo, t_table *table)
{
	if (get_time() - philo->last_eat_time >= table->time_to_die)
	{
		ph_print(philo, get_time(), "died");
		table->exit = TRUE;
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
	return (TRUE);
}

void		monitor(t_table *table)
{
	int	i;

	if (table->num_of_philos == 0)
		return ;
	while (!table->exit)
	{
		i = 0;
		while (i < table->num_of_philos)
		{
			if (check_starve(&table->philo[i], table))
				return ;
			i++;
		}
		if (table->num_of_must_eat != 0 && check_full(table))
			return ;
		usleep(100);
	}
}

void		end_dining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	pthread_mutex_destroy(table->print);
}
