/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:49:24 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 10:21:36 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*p;
	size_t		len;

	if (!*needle)
		return ((char *)haystack);
	p = haystack;
	len = ft_strlen(needle);
	while ((p = ft_strchr(p, *needle)) != 0)
	{
		if (ft_strncmp(p, needle, len) == 0)
			return ((char *)p);
		p++;
	}
	return (NULL);
}
