/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:28:07 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/14 21:28:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

/*
** digits after dot = -exponent
** when PRECISION is greater than exponent we have to substract from PRECISION
** exponent to full fill the value with zeros but exponent is already negative
** thats why we adding it
*/

void	rounding(t_vec *result, long index)
{
	if (DATA(result, index) < '9')
		DATA(result, index)++;
	else
	{
		while (index < (long)(result->length) - 1 && DATA(result, index) == '9')
			DATA(result, index++) = '0';
		if (DATA(result, index) == '.')
			index++;
		while (index < (long)(result->length) - 1 && DATA(result, index) == '9')
			DATA(result, index++) = '0';
		if (DATA(result, index) < '9')
			DATA(result, index)++;
		else
		{
			DATA(result, index) = '0';
			vec_pushback(result, '1', 1);
		}
	}
}

void	set_precision_helper(t_vec *result, long precision, long after_dot,
		t_one *vault)
{
	long	index;
	long	check_precision;
	int		round_point;
	int		after_rd_pt;
	int		zero_pr_case;

	check_precision = precision < 0 ? 6 : precision;
	index = after_dot - 1;
	after_rd_pt = 0;
	zero_pr_case = !check_precision && !HASH;
	round_point = DATA(result, index-- - check_precision) >= '5';
	while (index - check_precision >= 0)
	{
		after_rd_pt = round_point &&
				DATA(result, index - check_precision) != '0';
		if (after_rd_pt)
			break ;
		index--;
	}
	if (after_rd_pt)
		rounding(result, after_dot - check_precision + zero_pr_case);
	else if (round_point && (DATA(result,
			after_dot - check_precision + zero_pr_case) - '0') % 2)
		rounding(result, after_dot - check_precision + zero_pr_case);
	vec_popfront(result, after_dot - check_precision + zero_pr_case);
}

t_vec	*set_precision(t_vec *result, short exponent, t_one *vault)
{
	if (!result)
		return (result);
	if (exponent >= 0)
	{
		vec_pushfront(result, '0', PRECISION < 0 ? 6 : PRECISION);
		if (!PRECISION)
			vec_popfront(result, 1);
		return (result);
	}
	if (PRECISION == -exponent)
		return (result);
	if (PRECISION > -exponent)
		vec_pushfront(result, '0', PRECISION + exponent);
	else if (PRECISION < -exponent)
		set_precision_helper(result, PRECISION, -exponent, vault);
	return (result);
}
