/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:17 by daeunki2          #+#    #+#             */
/*   Updated: 2024/11/11 23:54:03 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_fork(t_table *table)
{
	int	i;

	i = 0;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
	{
		printf("Error: Memory allocation failed.\n");
		free(table->forks);
		return (1);
	}
	while(i < table->n_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return(0);
}

int	init_philo(t_table *table, t_philo **philo)
{
	int i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * table->n_philo);
	if (!*philo)
	{
		printf("Error: Memory allocation failed.\n");
		free(table->forks);
		return (1);
	}
	while(i < table->n_philo)
	{
        (*philo)[i].idx = i + 1;         
        (*philo)[i].table = table;       
        (*philo)[i].eat_count = 0;
        (*philo)[i].status = THINKING;
		i++;
	}
	return(0);
}

void	closing_time(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < table->n_philo)
	{
		pthread_join(philo[i].id, NULL);
		pthread_mutex_destroy(&table->forks[i]);
		i ++;
	}
}
