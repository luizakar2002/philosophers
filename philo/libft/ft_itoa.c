/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:39:24 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/28 19:58:59 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	t;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != 0 && i < size / 2)
	{
		t = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = t;
		i++;
	}
	return (str);
}

int		ft_intlen(int n)
{
	int			i;
	long long	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t = t * -1;
		i++;
	}
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				idx;
	int				is_negative;
	unsigned int	positive_n;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
		return (NULL);
	ft_memset(value, '\0', (ft_intlen(n) + 1));
	is_negative = n < 0 ? 1 : 0;
	positive_n = n < 0 ? -n : n;
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	if (is_negative)
		value[idx++] = '-';
	return (ft_strrev(value));
}
