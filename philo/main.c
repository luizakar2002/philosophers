#include "philo.h"

philo 			ph[10];

params	*init_param(params *p, char **argv)
{
	p->n_of_philo = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->n_of_eat = 0;
	if (argv[5])
		p->n_of_eat = ft_atoi(argv[5]);
	p->ph = malloc(sizeof(philo) * p->n_of_philo);
	pthread_mutex_init(&(p->mutex), NULL);
	return (p);
}

void	*routine(void *phi)
{
	pthread_mutex_lock(&(((philo *)phi)->mutex));
	// if (phi->index == 1)
	// {
	// 	phi->lf = 1;
	// 	phi->rf = 1;
	// }
	// else if (phi->index == phi->rule->n_of_philo)
	// {

	// }
	printf("thread i %d\n", ((philo *)phi)->index);
	pthread_mutex_unlock(&(((philo *)phi)->mutex));
}

int	main(int argc, char **argv)
{
	params 	*param;
	int		i;

	if (argc != 5 && argc != 6)
		return (1);
	param = malloc(sizeof(param));
	param = init_param(param, argv);
	i = 0;
	while (i < param->n_of_philo)
	{
		param->ph[i].index = i + 1;
		param->ph[i].mutex = param->mutex;
		param->ph[i].rule = param;
		if (pthread_create(&(param->ph[i].tid), NULL, &routine, &(param->ph[i])) != 0)
			return (2);
		i++;
	}
	i = 0;
	while (i < param->n_of_philo)
	{
		if (pthread_join(param->ph[i].tid, NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}
