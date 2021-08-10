/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:33:57 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/27 17:34:13 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *ptr;

	if (!(ptr = (void *)malloc(nitems * size)))
	{
		return (NULL);
	}
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
