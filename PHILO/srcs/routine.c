/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:08:08 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 14:13:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->table->num_of_philos == 1)
		return (philo_one(philo));
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 0.5);
	while (!(philo->table->exit))
	{
		if (eating(philo) == PH_EXIT)
			break ;
		if (sleeping(philo) == PH_EXIT)
			break ;
		if (thinking(philo) == PH_EXIT)
			break ;
	}
	return (NULL);
}

int	start_dining(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = get_time();
	while (i < table->num_of_philos)
	{
		if (pthread_create(&(table->philo[i].thread), NULL, routine, \
		(void *)&table->philo[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
