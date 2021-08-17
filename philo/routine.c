#include "philo.h"

void    live(philo *p)
{
    // printf("l %d\n", p->lf);
    // printf("r %d\n", p->rf);
    // pthread_mutex_lock(&(p->eat_mutex));
    pthread_mutex_lock(&(p->rule->fork_mutex[p->lf]));
    print(p->rule, p, " has taken a fork");
    pthread_mutex_lock(&(p->rule->fork_mutex[p->rf]));
    print(p->rule, p, " has taken a fork");
    pthread_mutex_lock(&(p->eat_mutex));
    print(p->rule, p, " is eating");
    p->last_eat = gettime();
    pthread_mutex_unlock(&(p->eat_mutex));
    usleep(p->rule->time_to_eat * 1000);
    // usleep(5000);
    p->eat_count++;
    pthread_mutex_unlock(&(p->rule->fork_mutex[p->rf]));
    pthread_mutex_unlock(&(p->rule->fork_mutex[p->lf]));
    // pthread_mutex_unlock(&(p->eat_mutex));

    print(p->rule, p, " is sleeping");
    usleep(p->rule->time_to_sleep * 1000);
    print(p->rule, p, " is thinking");
}