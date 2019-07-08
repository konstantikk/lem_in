/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:03:53 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 09:53:57 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_nitoi(int num, char *str, size_t len)
{
	str[0] = '-';
	while (len >= 1)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

static char			*ft_pitoi(int num, char *str, size_t len)
{
	while (len)
	{
		str[--len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	int		num;
	size_t	len;
	char	*str;
	int		sign;

	sign = (n < 0 ? 1 : 0);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	num = (n < 0 ? -1 * n : n);
	len = ft_intlen(num);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	if (num == 0)
		*str = '0';
	if (!sign)
		str = ft_pitoi(num, str, len);
	else
		str = ft_nitoi(num, str, len);
	return (str);
}
