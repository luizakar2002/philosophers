/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:41:12 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:41:15 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker(void *ph)
{
    int i;
    philo *p;

    p = (philo *)ph;
	while (1)
    {
        pthread_mutex_lock(&(p->mutex));
        if ((gettime() - p->last_eat) > p->rule->time_to_die)
        {
            print(p->rule, p, " died", 1);
            pthread_mutex_unlock(&(p->rule->dead_mutex));
            return ((void *)0);
        }
        pthread_mutex_unlock(&(p->mutex));
    }
}

void    *must_eat(void *ph)
{
    int i;
    philo *p;

    p = (philo *)ph;
    while (1)
    {
        pthread_mutex_lock(&(p->eat_mutex));
        i = 0;
        printf("aaaaaaa\n");
        while (i < p->rule->count)
        {
            if (p[i].eat_count == p[i].rule->n_of_eat)
                i++;
        }
        if (i == p->rule->count)
        {
            print(p->rule, p, " must eat", 1);
            pthread_mutex_unlock(&(p->rule->dead_mutex));
            return ((void *)0);                
        }
        pthread_mutex_unlock(&(p->eat_mutex));
    }
}

void	*routine(void *ph)
{
    philo       *p;
    pthread_t   tid;

    p = (philo *)ph;
    if (pthread_create(&tid, NULL, death_checker, p))
        error_exit(3);
	pthread_detach(tid);
    while (1)
        live(p);
}

void    create_threads(params *p)
{
    pthread_t   tid;
    philo       *ph;
    int         i;

    i = 0;
    ph = p->ph;
    ph->rule->start = gettime();
    while (i < p->count)
    {
        ph[i].last_eat = gettime();
        if (pthread_create(&tid, NULL, routine, &(ph[i])))
            error_exit(3);
		pthread_detach(tid); 
        i++;
    }
    if (p->n_of_eat > 0)
    {
        if (pthread_create(&tid, NULL, must_eat, p->ph))
            error_exit(3);
        pthread_detach(tid);
    }
}

int	main(int argc, char **argv)
{
	params 	*param;

	check_args(argc, argv);
	param = malloc(sizeof(params));
	if (!param)
		error_exit(1);
	init_param(param, argv);
	create_threads(param);
    pthread_mutex_lock(&(param->dead_mutex));
    exiting(param, param->ph);
	return (0);
}
