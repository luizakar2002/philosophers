#include "philo.h"

int	ft_atoi(const char *str)
{
	int sign;
	int nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

void	error_exit(int code)
{
	if (code == 1)
	{
		write(1, "No memory left for malloc\n", 26);
		exit(1);
	}
	else if (code == 2)
	{
		write(1, "Error: not able to init a mutex\n", 32);
		exit(1);
	}
	else if (code == 3)
	{
		write(1, "Error: not able to create a thread\n", 35);
		exit(1);
	}
	else if (code == 4)
	{
		write(1, "Error: wrong arguments\n", 23);
		exit(1);
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc != 5 && argc != 6)
		error_exit(4);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				error_exit(4);
			j++;
		}
		i++;
	}
}

long long	gettime(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	print(params *p, philo *ph, char *str)
{
	pthread_mutex_lock(&(p->write_mutex));
	// printf("%lli  %d  %s\n", gettime() - p->start, ph->index, str);
	printf("%lli ", gettime() - p->start);
	printf("%d ", ph->index + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(p->write_mutex));
	return ;
}