/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:40:40 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/24 19:40:55 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t temp;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (*(haystack + i))
	{
		j = 0;
		if (*(haystack + i) == *(needle + j))
		{
			temp = i;
			while (1)
			{
				if (!*(needle + j))
					return ((char*)haystack + temp);
				if (*(haystack + i++) != *(needle + j++))
					break ;
			}
			i = temp;
		}
		i++;
	}
	return (NULL);
}
