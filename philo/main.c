#include "philo.h"

void	death_checker(params *p, philo *ph)
{
    int i;

    i = 0;
	while (i < p->count)
    {
        if ((gettime() - ph[i].last_eat) > p->time_to_eat)
            p->died = 1;
        // printf("d %d\n", p->died);
        i++;
    }
}

void	*routine(void *ph)
{
    philo *p;

    p = (philo *)ph;
    // pthread_mutex_lock(&(p->mutex));
    if (p->index % 2)
        usleep(15000);
    // while (!(p->rule->died))
    while (1)
    {
        live(p);
        death_checker(p->rule, p);
    }
    // pthread_mutex_unlock(&(p->mutex));
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
        if (pthread_create(&tid, NULL, routine, &(ph[i])))
            error_exit(3);
        ph[i].last_eat = gettime();
        i++;
    }
	death_checker(p, ph);
    exiting(p, ph);
}

int	main(int argc, char **argv)
{
	params 	*param;

	check_args(argc, argv);
	param = malloc(sizeof(params));
	if (!param)
		error_exit(1);
	init_param(param, argv);
    // printf("d %d\n", param->ph[0].rule->died);
	create_threads(param);
	return (0);
}