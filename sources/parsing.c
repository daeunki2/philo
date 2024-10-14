/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:53:30 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/14 14:41:47 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_simple_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	parse_arguments(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	table->n_philo = ft_simple_atoi(argv[1]);
	table->t_die = ft_simple_atoi(argv[2]);
	table->t_eat = ft_simple_atoi(argv[3]);
	table->t_sleep = ft_simple_atoi(argv[4]);
	if (argc == 6)
		table->m_count = ft_atoi(argv[5]);
	else
		table->m_count = -1;
	if (table->n_philo <= 0 || table->t_die <= 0 || table->t_eat <= 0
		|| table->t_sleep <= 0 || (argc == 6 && table->m_count <= 0))
	{
		ft_printf("Error: Arguments must be positive integers.\n");
		return (1);
	}
	return (0);
}
