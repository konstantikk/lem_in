/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:45:48 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/27 19:30:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if ((temp = (char*)malloc(sizeof(char) * (length + 1))))
	{
		i = 0;
		while (*s)
			*(temp + i++) = f(*s++);
		*(temp + i) = '\0';
	}
	return (temp);
}
