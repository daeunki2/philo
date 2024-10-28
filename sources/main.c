/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/28 17:32:02 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
step :
parsing -- did !
intialize value from input -- did !
intialize value for the program
initalize mutexes , very important
run program
finish
*/

/*
look about threads ,
look mutexes

create a thread, 
pthread_create -> give a function to execute, all the thread will execute the same function !

the loop will be 
-eating
sleeping
thinking

(little problem you can encounter is :
if there is 4 philo 2 of them will eat at the same time 
and 2 waiting)
*/

int	main(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || (ft_vaild_argv(argv) != 0))
	{
		input_error();
		return (1);
	}
	return (0);
}

