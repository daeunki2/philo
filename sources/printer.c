/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:22 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/28 17:34:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	input_error(void)
{
	write(2, "input error\n", 12);
	write(2, "./philo number_of_philosophers", 29);
	write(2, " time_to_die time_to_eat time_to_sleep", 38);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
}
long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	write_msg(t_philosopher	*philo, char *msg)
{
	long long	time;

	time = timestamp();
	printf("%lld %i %s\n",time, philo->id, msg);
}