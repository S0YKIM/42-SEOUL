/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:08:08 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 15:12:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eating(t_philo *philo)
{
	if (philo->table->exit)
		return ;
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	ph_print(philo, get_time(), "has taken a fork");
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	ph_print(philo, get_time(), "has taken a fork");
	ph_print(philo, get_time(), "is eating");
	philo->last_eat_time = get_time();
	ph_usleep(philo->table, philo->table->time_to_eat);
	philo->eat_cnt++;
	if (philo->table->exit)
		return ;
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
}

static void	sleeping(t_philo *philo)
{
	if (philo->table->exit)
		return ;
	ph_print(philo, get_time(), "is sleeping");
	ph_usleep(philo->table, philo->table->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	if (philo->table->exit)
		return ;
	ph_print(philo, get_time(), "is thinking");
}

static void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 800);
	while (!(philo->table->exit))
	{
		eating(philo);
		if (philo->table->exit)
			break ;
		sleeping(philo);
		thinking(philo);
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
