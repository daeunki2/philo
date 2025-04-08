/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/08 16:21:43 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table		info;

	if (check_argv(argc, argv) != 0)
		return (-1);
	if (init_all(&info, argc, argv) != 0)
		return (-1);
	start_simulation(&info);
	return (0);
}
