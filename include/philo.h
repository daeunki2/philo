/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:07:42 by daeunki2          #+#    #+#             */
/*   Updated: 2024/11/11 23:52:31 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
    EATING,
    SLEEPING,
    THINKING,
    FULL,
    DIE
} t_status;

typedef struct s_philo
{   
    int             state;
    int             idx;
    int             eat_count;
    int             deja_eat;
    pthread_t       id;
    struct s_table  *table;
    t_status        status;
} t_philo;

typedef struct s_table
{
    int             n_philo;      // 철학자 수
    int             t_die;        // 죽기까지의 시간
    int             t_eat;        // 식사 시간
    int             t_sleep;      // 수면 시간
    int             m_count;      // 각 철학자가 먹어야 하는 횟수 (optional)
    pthread_mutex_t *forks;       // 포크를 나타내는 뮤텍스 배열
} t_table;


/*parsing.c*/
int	parse_arguments(int argc, char **argv, t_table *table);
int					ft_simple_atoi(char *str);
int					ft_vaild_argv(char **argv);
/*printer.c*/
void				input_error(void);
/*init.c*/
int	init_fork(t_table *table);
void	closing_time(t_table *table, t_philo *philo);
int init_philo(t_table *table, t_philo **philos);
/*utils.c*/
void	*philo_routine(void *arg);
t_philo	*create_philo(int id);
void	add_philo(t_philo **head, int id);
/*routine.c*/
void    *start_routine(void *data);
void	create_threads(t_philo *philos, t_table *table);

#endif