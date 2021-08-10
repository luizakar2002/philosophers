/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:11:21 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/30 19:27:55 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char *)s1 + idx) ==
				*((unsigned char *)s2 + idx))
			idx++;
		else
			return ((*((unsigned char *)s1 + idx)) -
						*((unsigned char *)s2 + idx));
	}
	return (0);
}
