/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:41:22 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:41:25 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    live(philo *p)
{
    pthread_mutex_lock(&(p->rule->fork_mutex[p->lf]));
    pthread_mutex_lock(&(p->rule->fork_mutex[p->rf]));
    print(p->rule, p, " has taken a fork", 0);
    print(p->rule, p, " is eating", 0);
    p->last_eat = gettime();
    sleeping(p->rule->time_to_eat);
    p->eat_count++;
    pthread_mutex_unlock(&(p->rule->fork_mutex[p->rf]));
    pthread_mutex_unlock(&(p->rule->fork_mutex[p->lf]));
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
