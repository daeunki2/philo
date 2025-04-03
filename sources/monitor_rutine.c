/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_rutine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:22:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/04/03 17:23:17 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (!table->is_dead)
	{
		i = 0;
		while (i < table->num_philos)
		{
			// 철학자가 너무 오랫동안 먹지 않았다면
			if (get_current_time() - table->philos[i].last_meal > table->time_to_die)
			{
				pthread_mutex_lock(&table->print_mutex);
				print_action(&table->philos[i], "died");
				
				// 사망 감지 후 is_dead 플래그 설정
				pthread_mutex_lock(&table->is_dead_mutex);
				table->is_dead = 1;
				pthread_mutex_unlock(&table->is_dead_mutex);
				
				pthread_mutex_unlock(&table->print_mutex);
				return (NULL);  // 모니터링 스레드 종료
			}
			i++;
		}
		usleep(1000);  // 너무 자주 확인할 필요는 없으므로 조금의 시간 대기
	}
	return (NULL);
}

