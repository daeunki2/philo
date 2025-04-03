/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 17:23:47 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_forks(t_philo *philo)
{
	t_table	*table = philo->table_info;

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_action(philo, "has taken a fork");
	}
}

void	philo_eat(t_philo *philo)
{
	t_table	*table;
    
	table = philo->table_info;
	pick_up_forks(philo);
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	usleep(table->time_to_eat * 1000);
    pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->table_info->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_table *table = philo->table_info;

	// 철학자가 죽었는지 확인하는 루프
	while (1)
	{
		pthread_mutex_lock(&table->is_dead_mutex);
		if (table->is_dead)  // 사망 플래그가 설정되면 루틴 종료
		{
			pthread_mutex_unlock(&table->is_dead_mutex);
			break;
		}
		pthread_mutex_unlock(&table->is_dead_mutex);

		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

// void	*philo_routine(void *arg)
// {
// 	t_philo *philo = (t_philo *)arg;
// 	t_table *table = philo->table_info;

// 	while (!table->is_dead)
// 	{
// 		philo_eat(philo);
// 		philo_sleep(philo);
// 		philo_think(philo);
// 	}
// 	return (NULL);
// }

// void	put_down_forks(t_philo *philo)
// {
// 	t_table	*table = philo->table_info;

// 	pthread_mutex_unlock(&table->forks[philo->left_fork]);
// 	pthread_mutex_unlock(&table->forks[philo->right_fork]);
// }

// void take_forks(t_philo *philo)
// {
//     t_table *table = philo->table_info;

//     // 홀수 철학자는 왼쪽 포크를 먼저, 짝수 철학자는 오른쪽 포크를 먼저 잡도록 처리
//     if (philo->id % 2 == 1)  // 홀수 번호 철학자
//     {
//         pthread_mutex_lock(&table->forks[philo->left_fork]);  // 왼쪽 포크 잡기
//         print_status(philo, "has taken left fork");

//         pthread_mutex_lock(&table->forks[philo->right_fork]);  // 오른쪽 포크 잡기
//         print_status(philo, "has taken right fork");
//     }
//     else  // 짝수 번호 철학자
//     {
//         pthread_mutex_lock(&table->forks[philo->right_fork]);  // 오른쪽 포크 먼저 잡기
//         print_status(philo, "has taken right fork");

//         pthread_mutex_lock(&table->forks[philo->left_fork]);  // 왼쪽 포크 잡기
//         print_status(philo, "has taken left fork");
//     }
// }


// void eat(t_philo *philo)
// {
//     long long current_time = get_current_time();
//     printf("Philosopher %d is eating\n", philo->id);
//     usleep(philo->table_info->time_to_eat * 1000); 
//     philo->last_meal = current_time;
//     philo->meal_count++;

//     printf("Philosopher %d finished eating\n", philo->id);
// }

// void sleep_philo(t_philo *philo)
// {
//     printf("Philosopher %d is sleeping\n", philo->id);
//     usleep(philo->table_info->time_to_sleep * 1000);
// }

// void think(t_philo *philo)
// {
//     printf("Philosopher %d is thinking\n", philo->id);
//     usleep(1000);
// }

// void *philo_routine(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;
//     t_table *table = philo->table_info;

//     while (!table->is_dead)
//     {
//         // 포크를 잡고 먹기
//         pthread_mutex_lock(&table->forks[philo->left_fork]);  // 왼쪽 포크 잡기
//         print_status(philo, "has taken left fork");

//         pthread_mutex_lock(&table->forks[philo->right_fork]);  // 오른쪽 포크 잡기
//         print_status(philo, "has taken right fork");

//         eat(philo);  // 먹기

//         // 포크 내려놓기
//         pthread_mutex_unlock(&table->forks[philo->left_fork]);
//         pthread_mutex_unlock(&table->forks[philo->right_fork]);

//         sleep_philo(philo);
// 		think(philo);
// 	}
//     return (NULL);
// }

/*
void	*philo_routine(void *arg)
{
    t_philo	*philo = (t_philo *)arg;  // 받은 인자를 t_philo *로 변환
    
    printf("I'm philo n.%d  ", philo->id);
    printf("왼쪽 %d 오른쪽 %d\n", philo->left_fork, philo->right_fork);
    return NULL;
}
*/