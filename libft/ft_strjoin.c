/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:38:42 by jziemann          #+#    #+#             */
/*   Updated: 2018/12/17 20:30:03 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char *)malloc(sizeof(char) * len);
		if (str)
		{
			if (len)
			{
				ft_strcpy(str, s1);
				ft_strcat(str, s2);
			}
			return (str);
		}
	}
	return (NULL);
}
