/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:17 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/07 16:59:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_table *table)
{
	int	index;
	int	safety;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (table->forks == NULL)
		return (-1);
	index = 0;
	while (index < table->num_philos)
	{
		safety = pthread_mutex_init(&table->forks[index], NULL);
		if (safety)
		{
			destroy_forks(table->forks, index);
			return (ft_error("fail to creat mutex\n"));
		}
		index++;
	}
	return (0);
}

int	init_philos(t_table *table)
{
	int	index;
	int	safty;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos == NULL)
		return (-1);
	index = 0;
	while (index < table->num_philos)
	{
		table->philos[index].id = index + 1;
		table->philos[index].left_fork = index;
		table->philos[index].right_fork = (index + 1) % table->num_philos;
		table->philos[index].last_meal = table->start_time;
		table->philos[index].meal_count = 0;
		table->philos[index].table_info = table;
		safty = pthread_mutex_init(&table->philos[index].last_meal_mutex, NULL);
		if (safty != 0)
		{
			clean_philos(table);
			return (ft_error("fail to creat mutex\n"));
		}
		index++;
	}
	return (0);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (ft_error("fail to init print mutex"));

	if (pthread_mutex_init(&table->is_dead_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		return (ft_error("fail to init is_dead mutex"));
	}
	return (0);
}

int	init_all(t_table *table, int argc, char **argv)
{
	table->is_dead = 0;
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	if (init_mutex(table) != 0)
		return(-1);
	if (init_forks(table) != 0)
		return (-1);
	if (init_philos(table) != 0)
	{
		destroy_forks(table->forks, table->num_philos);
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->is_dead_mutex);
		return (-1);
	}
	return (0);
}
