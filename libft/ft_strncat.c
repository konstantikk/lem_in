/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:27:14 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/22 06:07:17 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *dest;

	dest = s1;
	while (*dest)
		dest++;
	while (n > 0 && *s2)
	{
		*dest++ = *s2++;
		n--;
	}
	*dest = 0;
	return (s1);
}
