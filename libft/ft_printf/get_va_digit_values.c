/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_digit_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:08:14 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/16 21:44:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long		get_va_long(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list		tmp;
	long		i;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	i = va_arg(tmp, long);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (i);
}

long double	get_va_long_double(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list		tmp;
	long double i;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	i = va_arg(tmp, long double);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (i);
}

double		get_va_double(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list	tmp;
	double	i;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	i = va_arg(tmp, double);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (i);
}
