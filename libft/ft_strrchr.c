/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:47:57 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/23 21:10:44 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *temp;
	char *occur;

	temp = (char *)s;
	occur = (char *)s;
	if (c == 0)
	{
		while (*occur++)
			;
		return (--occur);
	}
	while (*temp)
	{
		if (*temp == c)
			occur = temp;
		temp++;
	}
	if (*occur == c)
		return (occur);
	else
		return (NULL);
}
