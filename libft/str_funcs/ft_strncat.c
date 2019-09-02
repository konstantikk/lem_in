/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:46:01 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/22 19:40:47 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2 && n--)
		*temp++ = *s2++;
	*temp = '\0';
	return (s1);
}
