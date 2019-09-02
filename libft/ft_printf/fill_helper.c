/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:26:04 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:41:23 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_hash(t_one *vault, t_buf *tbuf, size_t num,
		short *chars_number)
{
	if (FLAG == 'p' || (FLAG != 'o' &&
		!(num == 0 && (FLAG == 'x' || FLAG == 'X') && MODL == 0)))
		add_buf(tbuf, '0');
	if (FLAG == 'p')
		add_buf(tbuf, 'x');
	else if (FLAG == 'x' &&
			!(num == 0 && (FLAG == 'x' || FLAG == 'X') && MODL == 0))
		add_buf(tbuf, 'x');
	else if (FLAG == 'X' &&
			!(num == 0 && (FLAG == 'x' || FLAG == 'X') && MODL == 0))
		add_buf(tbuf, 'X');
	else if (FLAG == 'o' &&
			(num != 0 || PRECISION == 0) && PRECISION <= *chars_number)
	{
		if (WIDTH > *chars_number && MINUS == 0)
		{
			tbuf->i--;
		}
		MODL = 1;
		++(*chars_number);
		add_buf(tbuf, '0');
	}
}

void		select_sign(t_one *vault, t_buf *tbuf, long num)
{
	if (num < 0)
		add_buf(tbuf, '-');
	else if (PLUS == 1)
		add_buf(tbuf, '+');
	else if (SPACE == 1)
		add_buf(tbuf, ' ');
}

void		fill_num_width(t_one *vault, t_buf *tbuf,
			short *chars_number, short sign)
{
	if (WIDTH > PRECISION + sign && WIDTH > *chars_number + sign)
	{
		if (PRECISION > *chars_number)
			fill_buf(tbuf, ' ', WIDTH - PRECISION - sign);
		else if (ZERO == 1 && PRECISION < 0)
		{
			if ((FLAG == 'x' || FLAG == 'X') && HASH == 1 && MODL != 1)
			{
				apply_hash(vault, tbuf, sign, chars_number);
				MODL = 1;
			}
			if (FLAG == 'p')
				apply_hash(vault, tbuf, 0, chars_number);
			HASH = 3;
			fill_buf(tbuf, '0', WIDTH - *chars_number - sign);
		}
		else
			fill_buf(tbuf, ' ', WIDTH - *chars_number - sign);
	}
}

void		fill_num_precision(t_one *vault, t_buf *tbuf, short *chars_number)
{
	if (PRECISION >= WIDTH)
	{
		if (PRECISION > *chars_number)
			fill_buf(tbuf, '0', PRECISION - *chars_number);
	}
	else
	{
		if (WIDTH > PRECISION && WIDTH > *chars_number)
		{
			if (PRECISION > *chars_number)
				fill_buf(tbuf, '0', PRECISION - *chars_number);
		}
		else if (PRECISION > *chars_number)
			fill_buf(tbuf, '0', PRECISION - *chars_number);
	}
	if (PRECISION > *chars_number)
		--(*chars_number);
}
