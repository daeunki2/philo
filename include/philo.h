/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:07:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 17:23:06 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	int				meal_count;
	pthread_mutex_t	last_meal_mutex;
	struct s_table	*table_info;
}	t_philo;

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			is_dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	is_dead_mutex;
	t_philo			*philos;
}	t_table;

// /*clean_table.c*/
// /*init_table.c*/
void		destroy_forks(pthread_mutex_t *forks, int count);
void		clean_philos(t_table *table);
int			init_forks(t_table *table);
int			init_philos(t_table *table);
int			init_all(t_table *table, int argc, char **argv);
// /*monitor_rutine.c*/
// /*parsing.c*/
int			check_is_num(char *str);
int			check_argv(int argc, char *argv[]);
// /*philo_rutine.c*/
void		*philo_routine(void *arg);
// /*printer.c*/
int			ft_error(char *str);
int			input_error(void);
void		print_action(t_philo *philo, const char *msg);
// /*utils.c*/
int			ft_atoi(char *str);
int			ft_strlen(char *str);
long long	get_current_time(void);

#endif