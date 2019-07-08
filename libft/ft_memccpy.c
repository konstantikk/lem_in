/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:10:39 by jziemann          #+#    #+#             */
/*   Updated: 2018/12/04 22:11:00 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*ds;
	const unsigned char	*sr;

	ds = dst;
	sr = src;
	while (n--)
	{
		if (*sr == (unsigned char)c)
		{
			*ds = *sr;
			return (++ds);
		}
		*ds++ = *sr++;
	}
	return (NULL);
}
