/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:02:39 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/24 18:45:47 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp;

	temp = dst;
	while (*src && len--)
		*temp++ = *src++;
	while ((int)len-- > 0)
		*temp++ = '\0';
	return (dst);
}
