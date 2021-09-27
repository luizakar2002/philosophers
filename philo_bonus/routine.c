/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:42:05 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:42:07 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    live(philo *p)
{
    int e;

    sem_wait(p->rule->fork_sem);
    sem_wait(p->rule->fork_sem);
    print(p->rule, p, " has taken a fork", 0);
    print(p->rule, p, " is eating", 0);
    p->last_eat = gettime();
    sleeping(p->rule->time_to_eat);
    p->eat_count++;
    sem_post(p->rule->fork_sem);
    sem_post(p->rule->fork_sem);
    if (p->eat_count == p->rule->n_of_eat)
        sem_post(p->must_eat);
    print(p->rule, p, " is sleeping", 0);
    sleeping(p->rule->time_to_sleep);
    print(p->rule, p, " is thinking", 0);
}

void    sleeping(long long time)
{
    long long i;

    i = gettime();
    while (gettime() - i < time)
        usleep(10);
}
