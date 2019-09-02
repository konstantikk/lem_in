/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:08:06 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/27 23:52:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*(dst + i) && i != size)
		i++;
	if (*(dst + i))
		return (size + ft_strlen(src));
	else
	{
		while (i + 1 < size && *src)
			*(dst + i++) = *src++;
		*(dst + i) = '\0';
		return (i + ft_strlen(src));
	}
	return (0);
}
