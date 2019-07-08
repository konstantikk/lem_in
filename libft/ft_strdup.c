/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:04:26 by jziemann          #+#    #+#             */
/*   Updated: 2018/12/25 21:36:52 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(s1);
	temp = (char *)malloc(len + 1);
	if (temp)
	{
		temp = (char *)ft_memcpy(temp, s1, len);
		temp[len] = '\0';
		return (temp);
	}
	return (NULL);
}
