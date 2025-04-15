/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/15 16:10:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*do_philo(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table_info;
	if (philo->id % 2 != 1)
		ft_wait(table, table->time_to_eat);
	if (table->num_philos == 1)
	{
		pthread_mutex_lock(&table->forks_mutex[0]);
		ft_print(table, philo, "has taken a fork");
		ft_wait(table, table->time_to_die);
		pthread_mutex_unlock(&table->forks_mutex[0]);
		return (0);
	}
	while (some_death(table) == false)
	{
		while (get_forks(philo, table) != -1)
			usleep(100);
		do_sleep(philo, table);
		do_think(philo, table);
		usleep(500);
	}
	return (0);
}

int	get_forks(t_philo *philo, t_table *table)
{
	int	first;
	int	second;

	if (some_death(table) == true)
		return (-1);
	first = get_first_fork(philo);
	second = get_second_fork(philo);
	pthread_mutex_lock(&table->forks_mutex[first]);
	pthread_mutex_lock(&table->forks_mutex[second]);
	ft_print(table, philo, "has taken a fork");
	ft_print(table, philo, "has taken a fork");
	do_eat(philo, table);
	ft_wait(table, table->time_to_eat);
	pthread_mutex_unlock(&table->forks_mutex[second]);
	pthread_mutex_unlock(&table->forks_mutex[first]);
	pthread_mutex_lock(&philo->meal_num);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_num);
	return (-1);
}

void	do_eat(t_philo *philo, t_table *table)
{
	long long	time;

	if (some_death(table) == true)
		time = 0;
	else
	{
		pthread_mutex_lock(&(table->eat));
		time = ft_get_time() - table->start_time;
		philo->last_meal = time;
		pthread_mutex_unlock(&(table->eat));
		ft_print(table, philo, "is eating");
	}
}

void	do_sleep(t_philo *philo, t_table *table)
{
	if (some_death(table) == false)
	{
		ft_print(table, philo, "is sleeping");
		ft_wait(table, table->time_to_sleep);
	}
}

void	do_think(t_philo *philo, t_table *table)
{
	if (some_death(table) == false)
	{
		ft_print(table, philo, "is thinking");
	}
}

/*
// int	get_forks(t_philo *philo, t_table *table)
// {
// 	if (some_death(table) == true)
// 		return (-1);
// 	pthread_mutex_lock(&table->fork_condition);
// 	if (table->forks[philo->left_fork] == 0 \
// 		&& table->forks[philo->right_fork] == 0)
// 	{
// 		pthread_mutex_lock(&table->forks_mutex[philo->left_fork]);
// 		ft_print(table, philo, "has taken a fork");
// 		table->forks[philo->left_fork] = 1;
// 		pthread_mutex_lock(&table->forks_mutex[philo->right_fork]);
// 		ft_print(table, philo, "has taken a fork");
// 		table->forks[philo->right_fork] = 1;
// 		do_eat(philo, table);
// 		ft_wait(table, table->time_to_eat);
// 		table->forks[philo->left_fork] = 0;
// 		table->forks[philo->right_fork] = 0;
// 		pthread_mutex_unlock(&table->forks_mutex[philo->right_fork]);
// 		pthread_mutex_unlock(&table->forks_mutex[philo->left_fork]);
// 		pthread_mutex_unlock(&table->fork_condition);
// 		pthread_mutex_lock(&philo->meal_num);
// 		philo->meal_count++;
// 		pthread_mutex_unlock(&philo->meal_num);
// 		return (-1);
// 	}
// 	pthread_mutex_unlock(&table->fork_condition);
// 	return (0);
// }
*/