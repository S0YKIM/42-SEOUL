/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:08:08 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 14:08:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_lock(philo->table->print);
	print_philo(philo, get_time(), "has taken a fork");
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	print_philo(philo, get_time(), "has taken a fork");
	print_philo(philo, get_time(), "is eating");
	pthread_mutex_unlock(philo->table->print);
	philo->last_eat_time = get_time();
	while (get_time() - philo->last_eat_time < philo->table->time_to_eat)
		usleep(1000);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
}

static void	sleeping(t_philo *philo)
{
	(void)philo;
}

static void	thinking(t_philo *philo)
{
	(void)philo;
}

static void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 800);
	while (!(philo->table->someone_is_dead))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	philosophers(t_table *table)
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
