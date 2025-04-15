/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:22 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/15 16:11:30 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print(t_table *table, t_philo *philo, char *str)
{
	long long	time;

	if (some_death(table) == true)
		time = 0;
	else
	{
		pthread_mutex_lock(&table->print);
		if (some_death(table) == false)
		{
			time = ft_get_time() - table->start_time;
			printf("%lld	%d	%s\n", time, philo->id, str);
		}
		pthread_mutex_unlock(&table->print);
	}
}

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

int	free_msg(t_table *table, char *msg)
{
	free(table->forks);
	ft_error(msg);
	return (-1);
}

int	input_error(void)
{
	write(2, "input error\n", 12);
	write(2, "Usage : ./philo number_of_philosophers", 37);
	write(2, " time_to_die time_to_eat time_to_sleep", 38);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
	return (-1);
}
