# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

struct params;

typedef struct				philo
{
	int						index;
	//int						eating;
	int						lf;
	int						rf;
	long long				last_eat;
	int						eat_count;
	int						died;
	struct params			*rule;
	pthread_t				tid;
	pthread_mutex_t			mutex;
	pthread_mutex_t			eat_mutex;
}							philo;

typedef struct		params
{
	int				count;
	int 			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			n_of_eat;
	int				died;
	long long		start;
	struct philo	*ph;
	pthread_mutex_t write_mutex;
	pthread_mutex_t dead_mutex;
	pthread_mutex_t *fork_mutex;
}					params;

//***main.c***//
void    init_param(params *p, char **argv);
void    create_threads(params *p);
void	death_checker(params *p, philo *ph);

//***utils.c***//
void		print(params *p, philo *ph, char *str);
long long	gettime(void);
void		check_args(int argc, char **argv);
int			ft_isdigit(int c);
void		error_exit(int code);
int			ft_atoi(const char *str);

//***routine.c***//
void		live(philo *p);

//***init.c***//
void		exiting(params *p, philo *ph);

# endif
