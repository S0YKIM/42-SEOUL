/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:12 by sokim             #+#    #+#             */
/*   Updated: 2022/06/05 14:20:30 by sokim            ###   ########.fr       */
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
# define PH_EXIT 1
# define PH_CONTINUE 0

# define MAX_PHILOS 200
# define MAX_INT 2147483647
# define MIN_INT -2147483648

struct	s_philo;
typedef struct s_table
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				exit;
	long long		start_time;
	pthread_mutex_t	*monitor;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	struct s_philo	*philo;
}	t_table;

typedef struct s_philo
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
int			init(int argc, char **argv, t_table *table);

/*
 * validate.c
*/
int			is_valid_arguments(int argc, char **argv);

/*
 * utils.c
*/
long long	get_time(void);
void		ph_print(t_philo *philo, long long time, char *msg);
void		ph_usleep(t_table *table, long long time);
int			ft_atoi(const char *str);

/*
 * routine.c
*/
void		*routine(void *void_philo);
int			start_dining(t_table *table);

/*
 * monitor.c
*/
int			check_exit(t_philo *philo);
void		end_dining(t_table *table);

/*
 * philo.c
*/
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);
void		*philo_one(t_philo *philo);

#endif
