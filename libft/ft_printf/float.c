/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:20:41 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/16 23:44:58 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_printf.h"

/*
**	fraction = 1.{10011111001...1101} = {63}
**	чтобы избавится от дробного числа,
**	нужно fraction * 2 ^ 63, сохранив значение, т.е разделить на 2^63
**	получится fraction * 2 ^ 63 / 2 ^ 63
**	x = (-1)^sign * (fraction * 2 ^ 63 / 2 ^ 63) * 2 ^ (e - 16383)
**	упрощаем x = (-1)^sign * (fraction * 2 ^ 63 * 2 ^ - 63 * 2 ^ e - 16383)
**	x = (-1)^sign * (fraction * 2 ^ 63 * 2 ^ e - 63 - 16383)
**	x = (-1)^sign * (fraction * 2 ^ 63 * 2 ^ e - 16446)
*/

char	*calculations(t_vec *result, short exponent,
		unsigned sign, t_one *vault)
{
	char *str_res;

	result = fast_long_pow(result, exponent);
	if (result)
	{
		if (exponent < 0)
		{
			if (-exponent + 1 >= (long)result->length)
				vec_pushback(result, '0', -exponent + 1 - result->length);
			vec_insert(result, '.', 1, -exponent + 1);
		}
		else
			vec_pushfront(result, '.', 1);
		set_precision(result, exponent, vault);
		if (ZERO)
			vec_pushback((t_vec*)result, '0', PLUS || SPACE ?
			WIDTH - 1 - result->length : WIDTH - result->length);
		if (sign)
			vec_pushback(result, '-', 1);
		else if (PLUS)
			vec_pushback(result, '+', 1);
	}
	str_res = result ? ft_strdup(result->data) : NULL;
	vec_del(&result);
	return (str_res ? ft_strrev(str_res) : NULL);
}

void	exceptions(char flag, const char *str, const t_vec *result)
{
	char	*temp;
	int		index;

	if (!result)
		return ;
	index = -1;
	temp = ft_strchr(str, flag);
	while (++index < 3)
		vec_pushback((t_vec*)result, *temp++, 1);
}

char	*inf_nan_check(unsigned long fraction, unsigned sign, t_one *vault)
{
	const char	*val = "nanNANinfINF";
	const t_vec	*result = ft_vec_init(10);
	char		*str_res;

	if (fraction == FRACTION_MAX)
	{
		if (sign)
			vec_pushback((t_vec*)result, '-', 1);
		else if (PLUS)
			vec_pushback((t_vec*)result, '+', 1);
		FLAG == 'F' ?
		exceptions('I', val, result) : exceptions('i', val, result);
	}
	else if (fraction > FRACTION_MAX)
		FLAG == 'F' ?
		exceptions('N', val, result) : exceptions('n', val, result);
	str_res = result ? ft_strdup(result->data) : NULL;
	vec_del((t_vec**)&result);
	return (str_res);
}

char	*zero_case(unsigned sign, t_one *vault)
{
	const t_vec *result = ft_vec_init(40);
	char		*str_res;
	const int	check_precision = PRECISION < 0 ? 7 : PRECISION + 1;

	vec_pushback((t_vec*)result, '0', check_precision);
	if (check_precision > 0)
		vec_insert((t_vec*)result, '.', 1, 2);
	if (ZERO)
		vec_pushfront((t_vec*)result, '0', PLUS || SPACE ?
			WIDTH - 1 - result->length : WIDTH - result->length);
	if (sign)
		vec_pushfront((t_vec*)result, '-', 1);
	else if (PLUS)
		vec_pushfront((t_vec*)result, '+', 1);
	str_res = result ? ft_strdup(result->data) : NULL;
	vec_del((t_vec**)&result);
	return (str_res);
}

char	*ft_ftoa(long double value, t_one *vault)
{
	t_vec			*frac;
	unsigned long	fraction;
	short			exponent;
	unsigned		sign;

	take_exponent_and_fraction(&value, &exponent, &fraction, &sign);
	if (exponent == EXPONENT_MAX)
		return (inf_nan_check(fraction, sign, vault));
	if (!fraction)
		return (zero_case(sign, vault));
	exponent = exponent - (short)16446;
	if (!(frac = utoa(fraction)))
		return (NULL);
	return (calculations(frac, exponent, sign, vault));
}
