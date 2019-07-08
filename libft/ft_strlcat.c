/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:09:36 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 08:58:55 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	while (src[i] && (i + j + 1) < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
