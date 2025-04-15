/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:17 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/15 15:37:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_table *table)
{
	int	index;

	table->forks_mutex = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (table->forks == NULL)
		return (ft_error("pthread_t forks malloc fail"));
	index = 0;
	while (index < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks_mutex[index], NULL))
			return (ft_error("fail to creat forks mutex"));
		index++;
	}
	return (0);
}

int	init_philos(t_table *table)
{
	int	index;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos == NULL)
		return (ft_error("t_philo *phios malloc fail"));
	index = 0;
	while (index < table->num_philos)
	{
		table->philos[index].id = index + 1;
		table->philos[index].left_fork = index;
		table->philos[index].right_fork = (index + 1) % table->num_philos;
		table->philos[index].last_meal = 0;
		table->philos[index].meal_count = 0;
		table->philos[index].table_info = table;
		table->philos[index].is_dead = false;
		index++;
	}
	index = 0;
	while (index < table->num_philos)
	{
		if (pthread_mutex_init(&table->philos[index].meal_num, NULL))
			return (ft_error("fail to creat forks mutex"));
		index++;
	}
	return (0);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (ft_error("fail to init print mutex"));
	if (pthread_mutex_init(&table->eat, NULL) != 0)
		return (ft_error("fail to init eat mutex"));
	if (pthread_mutex_init(&table->fork_condition, NULL) != 0)
		return (ft_error("fail to init fork_condition mutex"));
	if (pthread_mutex_init(&table->death, NULL) != 0)
		return (ft_error("fail to init deaeth mutex"));
	return (0);
}

int	init_all(t_table *table, int argc, char **argv)
{
	table->someone_dead = false;
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	table->someone_dead = false;
	table->forks = malloc (sizeof(int) * table->num_philos);
	memset(table->forks, 0, sizeof(int) * table->num_philos);
	if (table->forks == NULL)
		return (-1);
	if (init_mutex(table) != 0)
		return (-1);
	if (init_forks(table) != 0)
		return (-1);
	if (init_philos(table) != 0)
		return (-1);
	return (0);
}
