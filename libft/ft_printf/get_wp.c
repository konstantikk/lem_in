/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 00:12:09 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:44:27 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_one *vault, t_va *valist)
{
	if (PRECISION < 0 && PRECISION != PSTARTING)
	{
		PRECISION = get_va_long(vault, valist, -(PRECISION), 0);
		if (PRECISION < 0)
		{
			MINUS = 1;
			PRECISION *= -1;
		}
	}
}

void	get_width(t_one *vault, t_va *valist)
{
	if (WIDTH < 0)
	{
		WIDTH = get_va_long(vault, valist, -(WIDTH), 0);
		if (WIDTH < 0)
		{
			MINUS = 1;
			WIDTH *= -1;
		}
	}
}

void	get_wp_from_args(t_one *vault, t_va *valist)
{
	if (MINUS == 1)
		ZERO = 0;
	get_width(vault, valist);
	get_precision(vault, valist);
}
