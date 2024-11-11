/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:42 by daeunki2          #+#    #+#             */
/*   Updated: 2024/11/11 23:57:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *start_routine(void *data)
{
	t_philo *philos;
//    int left;
//    int right;

	philos = (t_philo *)data;
    int left = (philos->idx - 1) % philos->table->n_philo;
    int right = philos->idx % philos->table->n_philo;
 //   right = (philos->idx - 1);
 //   left = (philos->idx % philos->table->n_philo);

    printf("philo idx = %d \nleft = %d\nright%d\n", philos->idx, left, right);    
	return (NULL);
}

void	create_threads(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_create(&philos[i].id, NULL, start_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(philos[i].id, 0);
		i++;
	}
	free(table->forks);
	free(philos);
}

// void    take_forks(t_table)
// {
    
// }
void    start_routine2(t_philo *philos, t_table *table)
{
    int left;
    int right;

    right = (philos->idx - 1);
    left = (philos->idx % table->n_philo);

    printf("philo idx = %d \nleft = %d\nright%d\n", philos->idx, left, right);    
}
