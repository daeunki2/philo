/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 17:06:02 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_current_time() + 100;
	i = 0;
	while (i < table->num_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table		info;
	pthread_t	monitor;

	if (check_argv(argc, argv) != 0)
		return (-1);
	if (init_all(&info, argc, argv) != 0)
		return (-1);
	if (pthread_create(&monitor, NULL, monitor_routine, &info) != 0)
	{
		printf("fail to creat monitor thread\n");
		return (-1);
	}
	start_simulation(&info);
	if (pthread_join(monitor, NULL) != 0)
	{
		printf("fail to join monitor thread\n");
		return (-1);
	}
	clean_all(&info);
	return (0);
}
