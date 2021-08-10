/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:15:13 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/27 20:28:41 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char			*osrc;
	size_t			nleft;

	osrc = (char *)src;
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			if ((*dest++ = *src++) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
