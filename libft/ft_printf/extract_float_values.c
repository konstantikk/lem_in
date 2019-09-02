/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:47:48 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/14 21:47:48 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

t_vec	*utoa(unsigned long fraction)
{
	t_vec *result;

	if (!(result = ft_vec_init(10)))
		return (NULL);
	if (!fraction)
		vec_pushback(result, '0', 1);
	while (fraction)
	{
		vec_pushback(result, fraction % 10 + '0', 1);
		fraction /= 10;
	}
	return (result);
}

int		take_exponent_and_fraction(long double *value, short *exponent,
		unsigned long *fraction, unsigned *sign)
{
	t_float hey;

	hey.value = *value;
	*exponent = hey.parsed_float.exponent;
	*fraction = hey.parsed_float.fraction;
	*sign = hey.parsed_float.sign;
	return (*sign);
}
