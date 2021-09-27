/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:41:55 by lukarape          #+#    #+#             */
/*   Updated: 2021/09/01 19:41:57 by lukarape         ###   ########.fr       */
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
        sem_wait(p->sem);
        if ((gettime() - p->last_eat) > p->rule->time_to_die)
        {
            print(p->rule, p, " died", 1);
            sem_post(p->rule->dead_sem);
            return ((void *)0);
        }
        sem_post(p->sem);
    }
}

void    *must_eat(void *ph)
{
    int i;
    philo *p;

    p = (philo *)ph;
    while (1)
    {
        sem_wait(p->eat_sem);
        i = 0;
        while (i < p->rule->count)
        {
            sem_wait(p->rule->ph[i].must_eat);
            i++;
        }
        print(p->rule, p, " all philosophers have eaten enough", 1);
        sem_post(p->rule->dead_sem);                
        sem_post(p->eat_sem);
    }
}

void	*routine(void *ph)
{
    pthread_t   tid;

    if (pthread_create(&tid, NULL, death_checker, ph))
        error_exit(3);
	pthread_detach(tid);
    while (1)
        live(ph);
}

void    create_threads(params *p)
{
    pthread_t   tid;
    philo       *ph;
    int         i;
    pid_t       pid;

    i = 0;
    ph = p->ph;
    ph->rule->start = gettime();
    pid = 1;
    while (i < p->count && pid != 0)
    {
        ph[i].last_eat = gettime();
        pid = fork();
        if (pid == -1)
            error_exit(3);
        if (pid == 0)
        {
            routine(&ph[i]);
        }
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
    int     i;

    i = 0;
	check_args(argc, argv);
	param = malloc(sizeof(params));
	if (!param)
		error_exit(1);
    sem_unlink("sem");
    sem_unlink("eat_sem");
    sem_unlink("write_sem");
    sem_unlink("dead_sem");
    sem_unlink("fork_sem");
    sem_unlink("must_eat");
	init_param(param, argv);
	create_threads(param);
    sem_wait(param->dead_sem);
    kill(0, SIGINT);
	return (0);
}
