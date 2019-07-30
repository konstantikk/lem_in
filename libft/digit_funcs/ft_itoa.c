/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:10:36 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/27 22:02:05 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	len(unsigned int n)
{
	size_t i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static	char	*condition(unsigned int n, char *t, size_t length, int flag)
{
	length += len(n);
	if (!(t = ft_strnew(length)))
		return (NULL);
	if (flag)
		t[0] = '-';
	while (length)
	{
		if (*(t + --length) != '-')
			*(t + length) = n % 10 + '0';
		n /= 10;
	}
	return (t);
}

char			*ft_itoa(int n)
{
	size_t			length;
	unsigned int	n_temp;
	char			*temp;
	int				flag;

	length = 0;
	flag = 0;
	n_temp = 0;
	temp = NULL;
	if (n == 0)
		length++;
	else	if (n < 0)
	{
		length++;
		flag = 1;
		n_temp = n * -1;
	}
	else
		n_temp = n;
	temp = condition(n_temp, temp, length, flag);
	return (temp);
}
