/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/14 14:42:07 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_table input;

    if (parse_arguments(argc, argv, &input) != 0)
        return (1);
    printf("YOUR INPUT\n");
    printf("num of philo is... %d\n", input.n_philo);
    printf("time to die is... %d\n", input.t_die);
    printf("time to eat is... %d\n", input.t_eat); 
    printf("time to sleep is... %d\n", input.t_sleep);
    return (0);
}
