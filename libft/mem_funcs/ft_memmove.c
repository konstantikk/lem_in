/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:42:58 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/24 17:52:39 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char *src_c;
	unsigned char		*dst_c;

	dst_c = dst;
	src_c = src;
	if (dst_c < src_c)
	{
		while (len--)
			*dst_c++ = *src_c++;
	}
	else if (dst_c > src_c)
	{
		while (len--)
			*(dst_c + len) = *(src_c + len);
	}
	return (dst);
}
