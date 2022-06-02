/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:12 by sokim             #+#    #+#             */
/*   Updated: 2022/06/02 14:25:16 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE 0
# define TRUE 1
# define SUCCESS 1
# define ERROR -1

# define MAX_PHILOS 200
# define MAX_INT 2147483647
# define MIN_INT -2147483648

struct	s_philo;
typedef struct	s_table
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				someone_is_dead;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	struct s_philo	*philo;
}	t_table;

typedef struct	s_philo
{
	pthread_t	thread;
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_cnt;
	long long	last_eat_time;
	t_table		*table;
}	t_philo;

/*
 * init.c
*/
int	init(int argc, char **argv, t_table *table);

/*
 * validate.c
*/
int	is_valid_arguments(int argc, char **argv);

/*
 * utils.c
*/
long long	get_time(void);
void		ph_print(t_philo *philo, long long time, char *msg);
void		ph_usleep(t_table *table, long long time);
int			ft_atoi(const char *str);

/*
 * philo.c
*/
int	philosophers(t_table *table);

#endif
