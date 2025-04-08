/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:21:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/07 17:05:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_forks(pthread_mutex_t *forks, int count)
{
	while (count >= 0)
	{
		count--;
		pthread_mutex_destroy(&forks[count]);
	}
	free(forks);
}

void	clean_philos(t_table *table)
{
	int		index;

	index = 0;
	while (index < table->num_philos)
	{
		pthread_mutex_destroy(&table->philos[index].last_meal_mutex);
		index++;
	}
}

void	clean_all(t_table *table)
{
	int	i;

	if (table->philos)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->philos[i].last_meal_mutex);
			i++;
		}
		free(table->philos);
	}
	if (table->forks)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->is_dead_mutex);
}
