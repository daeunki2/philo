/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:53:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 12:56:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (input_error());
	while (i != argc)
	{
		if (check_is_num(argv[i]) != 0)
			return (ft_error("only numbers\n"));
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
		return (ft_error("number_of_philosophers > 1."));
	if (ft_atoi(argv[2]) < 0)
		return (ft_error("time_to_die > 0."));
	if (ft_atoi(argv[3]) < 0)
		return (ft_error("time_to_eat > 0."));
	if (ft_atoi(argv[4]) < 0)
		return (ft_error("time_to_sleep > 0."));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return (ft_error("[philosopher_must_eat] > 0."));
	}
	return (0);
}
