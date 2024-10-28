/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:07:42 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/28 17:31:28 by daeunki2         ###   ########.fr       */
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

typedef struct s_philosopher
{
	int				id;
	long long		last_meal;
	int				eat_count;
	struct s_table	*table;
	pthread_t		thread;
}					t_philosopher;

typedef struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				m_count;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}					t_table;

/*parsing.c*/
int					parse_arguments(int argc, char **argv, t_table *table);
int					ft_simple_atoi(char *str);
int					ft_vaild_argv(char **argv);
/*printer.c*/
void				input_error(void);
/*init.c*/
/*utils.c*/

#endif