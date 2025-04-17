/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:21:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/17 12:56:35 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start_simulation(t_table *table)
{
	int		i;
	void	*philo_v;

	i = 0;
	table->start_time = ft_get_time();
	while (i < table->num_philos)
	{
		philo_v = (void *)&(table->philos[i]);
		if (pthread_create(&(table->philos[i].thread), NULL, do_philo, \
			philo_v) == -1)
			return (ft_error("thread creation fail"));
		i++;
	}
	ft_wait(table, table->time_to_eat);
	ft_check_die(table);
	return (0);
}

void	ft_check_die(t_table *table)
{
	while (some_death(table) == false)
	{
		pthread_mutex_lock(&(table->eat));
		if (time_check(table) != 0)
		{
			pthread_mutex_unlock(&(table->eat));
			break ;
		}
		if (table->must_eat != -1)
		{
			if (check_eat_num(table))
			{
				pthread_mutex_unlock(&(table->eat));
				break ;
			}
		}
		pthread_mutex_unlock (&(table->eat));
		usleep(200);
	}
	ft_clean_all(table);
}

int	time_check(t_table *table)
{
	long long	time;
	int			i;

	i = 0;
	while (i < table->num_philos)
	{
		time = ft_get_time() - table->start_time;
		if ((time - table->philos[i].last_meal) > table->time_to_die)
		{
			pthread_mutex_lock(&table->print);
			table->philos[i].is_dead = true;
			pthread_mutex_lock(&table->death);
			table->someone_dead = true;
			pthread_mutex_unlock(&table->death);
			printf("%lld	%d	is died\n", time, table->philos[i].id);
			pthread_mutex_unlock(&table->print);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_eat_num(t_table *table)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_num);
		check += (table->must_eat != -1 && table->philos[i].meal_count \
			>= table->must_eat);
		pthread_mutex_unlock(&table->philos[i++].meal_num);
	}
	if (check == table->num_philos)
	{
		pthread_mutex_lock(&table->death);
		table->someone_dead = true;
		pthread_mutex_unlock(&table->death);
		return (1);
	}
	return (0);
}

void	ft_clean_all(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i++].thread, NULL);
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&(table->forks_mutex[i++]));
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&(table->philos[i++].meal_num));
	}
	free(table->forks_mutex);
	free(table->forks);
	free(table->philos);
	pthread_mutex_destroy(&table->fork_condition);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->eat);
	pthread_mutex_destroy(&table->death);
}

/*
int	check_eat_num(t_table *table)
{
	long long	time;
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_num);
		check += (table->must_eat != -1 && table->philos[i].meal_count \
			>= table->must_eat);
		pthread_mutex_unlock(&table->philos[i++].meal_num);
	}
	if (check == table->num_philos)
	{
		pthread_mutex_lock(&table->print);
		pthread_mutex_lock(&table->death);
		table->someone_dead = true;
		pthread_mutex_unlock(&table->death);
		time = ft_get_time() - table->start_time;
		printf("%lldms	all philo eat %d time\n", time, table->must_eat);
		pthread_mutex_unlock(&table->print);
		return (1);
	}
	return (0);
}
*/
