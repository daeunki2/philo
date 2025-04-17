/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:53:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/17 09:56:33 by daeunki2         ###   ########.fr       */
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
			return (ft_error("only numbers or with only '1'sign."));
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
		return (ft_error("1 <= number_of_philosophers <= intmax."));
	if (ft_atoi(argv[2]) < 0)
		return (ft_error("0 < time_to_die <= intmax."));
	if (ft_atoi(argv[3]) < 0)
		return (ft_error("0 < time_to_eat <= intmax."));
	if (ft_atoi(argv[4]) < 0)
		return (ft_error("0 < time_to_sleep <= intmax."));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return (ft_error("0 < [philosopher_must_eat] <= intmax."));
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

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
	if (result > 2147483647)
		return (-1);
	return ((int)result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (0);
}
