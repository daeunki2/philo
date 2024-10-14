/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:07:42 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/14 14:37:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H
# include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philosopher {
    int id;                     // 철학자의 ID
    long long last_meal;        // 마지막 식사 시간 (밀리초 단위)
    int eat_count;              // 현재까지 먹은 횟수
    struct s_table *table;      // 테이블 구조체 포인터
 //   pthread_t thread;           // 철학자 스레드
} t_philosopher;


typedef struct s_table {
    int n_philo;     // 철학자 수
    int t_die;                // 죽기까지 걸리는 시간 (밀리초 단위)
    int t_eat;                // 식사 시간
    int t_sleep;              // 수면 시간
    int m_count;             // (옵션) 최소 식사 횟수
  //  pthread_mutex_t *forks;         // 포크의 뮤텍스 배열
 //   t_philosopher *philosophers;    // 철학자 구조체 배열
} t_table;

int parse_arguments(int argc, char **argv, t_table *table);
int ft_simple_atoi(char *str);
#endif