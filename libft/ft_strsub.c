/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:32:44 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 08:57:14 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if (s)
	{
		substr = (char *)malloc(len + 1);
		if (substr)
		{
			while (len--)
				substr[i++] = s[start++];
			substr[i] = '\0';
			return (substr);
		}
	}
	return (NULL);
}
