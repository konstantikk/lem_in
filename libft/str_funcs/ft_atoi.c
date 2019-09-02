/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:44:02 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/24 18:59:34 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *src)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*src == 32 || (*src >= 9 && *src <= 13))
		src++;
	if (*src == '+' || *src == '-')
		*src++ == '-' ? (sign *= -1) : (sign *= 1);
	while (*src >= '0' && *src <= '9')
		result = result * 10 + (*src++ - '0');
	return (result * sign);
}
