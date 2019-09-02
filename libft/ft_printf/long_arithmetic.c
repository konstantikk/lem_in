/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:56:40 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/14 21:56:43 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

t_vec	*fast_long_pow(t_vec *vec, short power)
{
	short		carry;
	short		pow;
	const short	base = power > 0 ? 2 : 5;
	size_t		i;

	if (!vec)
		return (NULL);
	pow = power > 0 ? power : -power;
	while (pow--)
	{
		i = -1;
		carry = 0;
		while (++i < vec->length)
		{
			carry += (DATA(vec, i) - '0') * base;
			DATA(vec, i) = carry % 10 + '0';
			carry /= 10;
		}
		if (carry)
			vec_pushback(vec, carry % 10 + '0', 1);
	}
	return (vec);
}
