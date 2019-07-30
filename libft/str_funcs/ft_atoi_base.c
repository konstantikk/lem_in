/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:34:38 by vlegros           #+#    #+#             */
/*   Updated: 2019/03/20 00:29:20 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		base(int c, int base)
{
	char	str[16];
	int		i;

	i = 0;
	ft_strcpy(str, "0123456789ABCDEF");
	while (i < base)
	{
		if (c == *(str + i) || c == *(str + i) + 32)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *src, int src_base)
{
	int result;

	result = 0;
	while (*src == 32 || (*src >= 9 && *src <= 13))
		src++;
	if (*src++ == '0' && (*src == 'x' || *src == 'X'))
		src++;
	while (base(*src, src_base) != -1)
		result = result * src_base + base(*src++, src_base);
	return (result);
}
