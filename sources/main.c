/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:50 by daeunki2          #+#    #+#             */
/*   Updated: 2024/11/11 23:48:59 by daeunki2         ###   ########.fr       */
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

//  void	print(int	i)
//  {
// 	printf("philosoper id = %d\n", i);
//  }

// int	main(int argc, char **argv)
// {
// 	t_table	table;
// 	t_philosopher	philo;
// 	int				i;
	
// 	table.philosophers = NULL;
// 	if ((argc != 5 && argc != 6) || (ft_vaild_argv(argv) != 0))
// 	{
// 		input_error();
// 		return (1);
// 	}//스레드를 만들고 실행시켜 보자!
// 	if (parse_arguments(argc, argv, &table) !=0)
// 	{
// 		printf("변환오류\n");
// 		return(1);
// 	}
// 	i = 0;
// 	pthread_create(&philo, NULL, (void *)print, &i);
// 	pthread_join(&philo);
	
// 	return (0);
// }


int	main(int argc, char** argv)
{
	t_table	table;
	t_philo *philo;

	if ((argc != 5 && argc != 6) || (ft_vaild_argv(argv) != 0))
	{
		input_error();
		return (1);
	}
	if (parse_arguments(argc, argv, &table) !=0)
	{
		printf("변환오류\n");
		return(1);
	}
	if (init_fork(&table, philo) != 0 || init_philo(&table, philo) != 0)
		return(-1);
	create_threads(philo, &table);

	return (0);
}
