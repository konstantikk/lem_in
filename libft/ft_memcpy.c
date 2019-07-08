/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:54:06 by jziemann          #+#    #+#             */
/*   Updated: 2018/12/14 20:01:22 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ds;
	unsigned char		*sr;

	if (dst == src)
		return (dst);
	ds = dst;
	sr = (unsigned char *)src;
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
