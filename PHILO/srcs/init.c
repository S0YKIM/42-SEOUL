/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:08 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 15:11:40 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	validate_table(t_table *table)
{
	if (table->num_of_philos < 0 || table->num_of_philos > MAX_PHILOS)
		return (FALSE);
	if (table->time_to_die < 0)
		return (FALSE);
	if (table->time_to_eat < 0)
		return (FALSE);
	if (table->time_to_sleep < 0)
		return (FALSE);
	if (table->num_of_must_eat < 0)
		return (FALSE);
	return (TRUE);
}

static int	init_table(int argc, char **argv, t_table *table)
{
	if (!memset(table, 0, sizeof(t_table)))
		return (ERROR);
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->num_of_must_eat = 0;
	table->exit = FALSE;
	table->start_time = 0;
	if (argc == 6)
		table->num_of_must_eat = ft_atoi(argv[5]);
	if (!validate_table(table))
		return (ERROR);
	return (SUCCESS);
}

static int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->num_of_philos);
	if (!table->fork)
		return (ERROR);
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) == ERROR)
			return (ERROR);
		i++;
	}
	table->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!table->print)
		return (ERROR);
	if (pthread_mutex_init(table->print, NULL) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philos);
	if (!table->philo)
		return (ERROR);
	while (++i <= table->num_of_philos)
	{
		if (!memset(&table->philo[i], 0, sizeof(t_philo)))
			return (ERROR);
		table->philo[i].id = i;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->num_of_philos;
		table->philo[i].table = table;
	}
	return (SUCCESS);
}

int	init(int argc, char **argv, t_table *table)
{
	if (init_table(argc, argv, table) == ERROR)
		return (FALSE);
	if (init_mutex(table) == ERROR)
		return (FALSE);
	if (init_philo(table) == ERROR)
		return (FALSE);
	return (TRUE);
}
