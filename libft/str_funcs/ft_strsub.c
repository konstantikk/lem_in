/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:23:05 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/26 20:50:28 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	if (!s)
		return (NULL);
	if ((temp = (char*)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (*s && i++ < start)
			s++;
		i = 0;
		while (i < len && *s)
			*(temp + i++) = *s++;
		*(temp + i) = '\0';
	}
	return (temp);
}
