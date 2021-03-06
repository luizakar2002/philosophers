/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:40:54 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:41:06 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_mutex(params *p)
{
    int i;

    if (pthread_mutex_init(&(p->write_mutex), NULL))
        error_exit(2);
    if (pthread_mutex_init(&(p->dead_mutex), NULL))
        error_exit(2);
    pthread_mutex_lock(&(p->dead_mutex));
    p->fork_mutex = malloc(sizeof(pthread_mutex_t) * p->count);
    if (!(p->fork_mutex))
        error_exit(1);
    i = 0;
    while (i < p->count)
    {
        if (pthread_mutex_init(&(p->fork_mutex[i]), NULL))
            error_exit(2);
        i++;
    }
}

void    init_philo(params *p)
{
    int i;

    i = 0;
    while (i < p->count)
    {
        p->ph[i].index = i;
        p->ph[i].lf = i;
        p->ph[i].rf = (i + 1) % p->count;
        p->ph[i].eat_count = 0;
        p->ph[i].rule = p;
        if (pthread_mutex_init(&(p->ph[i].mutex), NULL))
            error_exit(2);
        if (pthread_mutex_init(&(p->ph[i].eat_mutex), NULL))
            error_exit(2);
        i++;
    }
}

void    init_param(params *p, char **argv)
{
	p->count = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->n_of_eat = 0;
	if (argv[5])
		p->n_of_eat = ft_atoi(argv[5]);
	p->ph = malloc(sizeof(philo) * p->count);
    if (!(p->ph))
        error_exit(1);
    init_philo(p);
    init_mutex(p);
}

void	exiting(params *p, philo *ph)
{
	int i;

	i = 0;
	while (i < p->count)
	{
		pthread_mutex_destroy(&(p->fork_mutex[i]));
        pthread_mutex_destroy(&(ph[i].mutex));
        pthread_mutex_destroy(&(ph[i].eat_mutex));
		i++;
	}
	pthread_mutex_destroy(&p->write_mutex);
}
