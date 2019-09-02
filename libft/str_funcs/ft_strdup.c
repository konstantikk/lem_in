/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:33:05 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/22 15:00:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	length;

	length = ft_strlen(s1);
	temp = (char*)malloc(sizeof(char) * (length + 1));
	if (temp)
		ft_memcpy((void*)temp, s1, length + 1);
	return (temp);
}
