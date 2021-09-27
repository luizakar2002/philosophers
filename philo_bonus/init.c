/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:41:47 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:41:49 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_sem(params *p)
{
    p->write_sem = sem_open("write_sem", 0777, O_CREAT, 1);
    p->dead_sem = sem_open("dead_sem", 0777, O_CREAT, 0);
    p->fork_sem = sem_open("fork_sem", 0777, O_CREAT, p->count);
}

void    init_philo(params *p)
{
    int i;

    i = 0;
    while (i < p->count)
    {
        p->ph[i].index = i;
        p->ph[i].eat_count = 0;
        p->ph[i].rule = p;
        p->ph[i].sem = sem_open("sem", 0777, O_CREAT, 1);
        p->ph[i].eat_sem = sem_open("eat_sem", 0777, O_CREAT, 1);
        p->ph[i].must_eat = sem_open("must_eat", 0777, O_CREAT, 0);
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
    init_sem(p);
}
