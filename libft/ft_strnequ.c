/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:27:58 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 19:25:23 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	unsigned int i;

	i = 0;
	if (s1 && s2)
	{
		if ((s1[i] && !s2[i]) || (!s1[i] && !s2[i]) || len == 0)
			return (1);
		while (s1[i] && s1[i] == s2[i] && len - 1)
		{
			i++;
			len--;
		}
		if (s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
