/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:34:39 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/20 23:30:52 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if ((temp = malloc(size)))
	{
		ft_bzero(temp, size);
		if (USE_GC)
			ft_put_in_gc(temp);
	}
	return (temp);
}
