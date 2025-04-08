/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:07:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/08 16:51:03 by daeunki2         ###   ########.fr       */
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
	bool			is_dead;
	struct s_table	*table_info;
}	t_philo;

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			someone_dead;
	long long		start_time;
	int				*forks;
	pthread_mutex_t	fork_condition;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	*forks_mutex;
	t_philo			*philos;
}	t_table;

// /*check_clean.c*/
void		ft_check_die(t_table *table);
int			time_check(t_table *table);
int			check_eat_num(t_table *table);
void		ft_clean_all(t_table *table);
// /*init_table.c*/
int			init_forks(t_table *table);
int			init_philos(t_table *table);
int			init_mutex(t_table *table);
int			init_all(t_table *table, int argc, char **argv);
// /*main.c */
int			start_simulation(t_table *table);
// /*parsing.c*/
int			check_is_num(char *str);
int			check_argv(int argc, char *argv[]);
// /*philo_rutine.c*/
void		*do_philo(void *arg);
void		do_eat(t_philo *philo, t_table *table);
void		do_sleep(t_philo *philo, t_table *table);
void		do_think(t_philo *philo, t_table *table);
int			get_forks(t_philo *philo, t_table *table);
// /*printer.c*/
int			ft_error(char *str);
int			input_error(void);
void		ft_print(t_table *table, t_philo *philo, char *str);
// /*utils.c*/
int			ft_atoi(char *str);
int			ft_strlen(char *str);
long long	ft_get_time(void);
void		ft_wait(t_table *param, int time);

#endif