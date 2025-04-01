/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:22 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/01 17:19:13 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
