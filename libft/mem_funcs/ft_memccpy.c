/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:10:13 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/24 15:55:58 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*src_c;
	char unsigned		*dst_c;

	dst_c = dst;
	src_c = src;
	while (n--)
	{
		*dst_c++ = *src_c;
		if (*src_c++ == (unsigned char)c)
			return (dst_c);
	}
	return (NULL);
}
