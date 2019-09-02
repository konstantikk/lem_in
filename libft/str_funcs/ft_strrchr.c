/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:12:12 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/22 22:44:03 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t length;

	length = ft_strlen(s);
	while (*(s + length - 1) && length >= 1)
	{
		if (*(s + length - 1) == (char)c)
			return ((char*)s + length - 1);
		length--;
	}
	if (*(s + ft_strlen(s)) == (char)c)
		return ((char*)s + ft_strlen(s));
	return (NULL);
}
