/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:53:30 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 12:35:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_vaild_argv(char **argv)
{
	int	k;
	int	i;

	k = 1;
	while (argv[k] != NULL)
	{
		i = 0;
		while (argv[k][i] != '\0')
		{
			if (argv[k][i] < '0' || argv[k][i] > '9')
				return (-1);
			i++;
		}
		if (i == 0)
			return (-1);
		k = k + 1;
	}
	return (0);
}

int	parse_arguments(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	table->n_philo = ft_simple_atoi(argv[1]);
	table->t_die = ft_simple_atoi(argv[2]);
	table->t_eat = ft_simple_atoi(argv[3]);
	table->t_sleep = ft_simple_atoi(argv[4]);
	if (argc == 6)
		table->m_count = ft_simple_atoi(argv[5]);
	else
		table->m_count = -1;
	if (table->n_philo <= 0 || table->t_die <= 0 || table->t_eat <= 0
		|| table->t_sleep <= 0 || (argc == 6 && table->m_count <= 0))
	{
		printf("Error: Arguments must be positive integers.\n");
		return (1);
	}
	return (0);
}
