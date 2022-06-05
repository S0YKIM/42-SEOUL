/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:06:57 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 14:15:15 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philo *philo)
{
	if (check_exit(philo))
		return (PH_EXIT);
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	ph_print(philo, get_time(), "has taken a fork");
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	ph_print(philo, get_time(), "has taken a fork");
	ph_print(philo, get_time(), "is eating");
	philo->last_eat_time = get_time();
	ph_usleep(philo->table, philo->table->time_to_eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
	if (check_exit(philo))
		return (PH_EXIT);
	return (PH_CONTINUE);
}

int	sleeping(t_philo *philo)
{
	if (check_exit(philo))
		return (PH_EXIT);
	ph_print(philo, get_time(), "is sleeping");
	ph_usleep(philo->table, philo->table->time_to_sleep);
	return (PH_CONTINUE);
}

int	thinking(t_philo *philo)
{
	if (check_exit(philo))
		return (PH_EXIT);
	ph_print(philo, get_time(), "is thinking");
	return (PH_CONTINUE);
}

void	*philo_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	ph_print(philo, get_time(), "has taken a fork");
	ph_usleep(philo->table, philo->table->time_to_die);
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	ph_print(philo, get_time(), "died");
	philo->table->exit = TRUE;
	return ((void *) NULL);
}
