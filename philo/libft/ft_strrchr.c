/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:24:35 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/27 17:25:16 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *ptr;

	ptr = str;
	while (*ptr)
	{
		ptr++;
	}
	while (ptr != str - 1)
	{
		if (*ptr == c)
		{
			return ((char *)ptr);
		}
		ptr--;
	}
	ptr = 0;
	return ((char *)ptr);
}
