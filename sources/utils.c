/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:07:01 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/15 16:07:12 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_get_time(void)
{
	long long		sec;
	struct timeval	time;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (sec);
}

void	ft_wait(t_table *param, int time)
{
	long long	now_time;
	long long	start_time;

	start_time = ft_get_time();
	while (some_death(param) == false)
	{
		now_time = ft_get_time();
		if (now_time - start_time >= time)
			break ;
		usleep(300);
	}
}

bool	some_death(t_table *table)
{
	pthread_mutex_lock(&table->death);
	if (table->someone_dead == true)
	{
		pthread_mutex_unlock(&table->death);
		return (true);
	}
	pthread_mutex_unlock(&table->death);
	return (false);
}

int	get_first_fork(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
		return (philo->left_fork);
	return (philo->right_fork);
}

int	get_second_fork(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
		return (philo->right_fork);
	return (philo->left_fork);
}
