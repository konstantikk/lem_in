/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:51:15 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/20 18:50:25 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define E(x) s[x] == ' ' || s[x] == '\t' || s[x] == '\n' || s[x] == '\0'

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	last_not;

	begin = 0;
	end = 0;
	last_not = 0;
	if (!s)
		return (NULL);
	while (E(end))
	{
		begin++;
		end++;
	}
	while (s[end])
	{
		if (!(E(end)))
			if (E(end + 1))
				last_not = end;
		end++;
	}
	return (ft_strsub(s, begin, last_not - begin + 1));
}
