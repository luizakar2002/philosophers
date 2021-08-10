# ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

struct params;

typedef struct philo
{
	int				index;
	int				lf;
	int				rf;
	struct params			*rule;
	pthread_t		tid;
	pthread_mutex_t mutex;
}				philo;

typedef struct params
{
	int				n_of_philo;
	int 			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			n_of_eat;
	int				time_to_think;
	struct philo			*ph;
	pthread_mutex_t mutex;
}				params;

params	*init_param(params *p, char **argv);

# endif
