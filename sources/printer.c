/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:22 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 17:10:38 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(t_philo *philo, const char *msg)
{
	t_table 	*table;
	long long	time_stamp;
	
	table= philo->table_info;
	time_stamp = get_current_time() - table->start_time;
	pthread_mutex_lock(&table->print_mutex);
	printf("[%lld] %d %s\n", time_stamp, philo->id, msg);
	pthread_mutex_unlock(&table->print_mutex);
}

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	input_error(void)
{
	write(2, "input error\n", 12);
	write(2, "Usage : ./philo number_of_philosophers", 37);
	write(2, " time_to_die time_to_eat time_to_sleep", 38);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
	return (-1);
}
