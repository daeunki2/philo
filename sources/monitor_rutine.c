/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_rutine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:22:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/07 17:00:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_someone_dead(t_table *table)
{
	int			i;
	long long	time;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].last_meal_mutex);
		time = get_current_time() - table->philos[i].last_meal;
		pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
		if (time > table->time_to_die)
		{
			pthread_mutex_lock(&table->is_dead_mutex);
			if (!table->is_dead)
			{
				table->is_dead = true;
				pthread_mutex_unlock(&table->is_dead_mutex);
				print_action(&table->philos[i], "died");
			}
			else
				pthread_mutex_unlock(&table->is_dead_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	all_philos_done(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].last_meal_mutex);
		if (table->philos[i].meal_count < table->must_eat)
		{
			pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
			return (false);
		}
		pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
		i++;
	}
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (is_someone_dead(table))
			break ;
		if (table->must_eat != -1 && all_philos_done(table))
			break ;
		usleep(1000);
	}
	return (NULL);
}
