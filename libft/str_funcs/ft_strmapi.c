/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:59:08 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/27 19:30:27 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if ((temp = (char*)malloc(sizeof(char) * (length + 1))))
	{
		i = -1;
		while (++i < length)
			*(temp + i) = f(i, *(s + i));
		*(temp + i) = '\0';
	}
	return (temp);
}
