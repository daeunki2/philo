/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/01 17:46:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
int	opening_time(t_table *info)
{
	int	i;
	int	f;

	i = 0;
	while (i < info->num_philos)
	{
		f = pthread_create \
		(&(info->philos[i].thread), NULL, philo_routine, &(info->philos[i]));
		if (f != 0)
		{
			printf("Error\nFailed to create thread for philosopher %d\n", i);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	closing_time(t_table *info)
{
	int	index;
	int	safety;

	index = 0;
	while (index < info->num_philos)
	{
		safety = pthread_join(info->philos[index].thread, NULL);
		if (safety != 0)
		{
			printf("Error\nFailed to join philosopher thread %d\n", index);
			return (-1);
		}
		index++;
	}
	return (0);
}
*/
int	main(int argc, char **argv)
{
	t_table		info;
	pthread_t	monitor;

	if (check_argv(argc, argv) != 0)
		return (-1);
	if (init_all(&info, argc, argv) != 0)
		return (-1);
	// opening_time(&info);
	// if (pthread_create(&monitor, NULL, monitor_routine, &info) != 0)
	// {
	// 	printf("fail to creat monitor thread\n");
	// 	return (-1);
	// }
	// closing_time(&info);
	// if (pthread_join(monitor, NULL) != 0)
	// {
	// 	printf("fail to join monitor thread\n");
	// 	return (-1);
	// }
	// clean_all(&info);
	return (0);
}
