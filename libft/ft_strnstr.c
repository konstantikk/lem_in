/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:15:03 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/28 15:31:41 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len1;
	char		*p;

	p = 0;
	len1 = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	len1 = ft_strlen(needle);
	while (*haystack && len-- >= len1)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len1) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
