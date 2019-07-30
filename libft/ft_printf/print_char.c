/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 02:25:50 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:46:01 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	print_char_c(t_one *vault, t_buf *tbuf, char c)
{
	char filler;

	filler = ZERO == 1 ? '0' : ' ';
	if (MINUS == 1)
		add_buf(tbuf, c);
	while (--WIDTH > 0)
		add_buf(tbuf, filler);
	if (MINUS == 0)
		add_buf(tbuf, c);
	print_buf(tbuf);
	return (0);
}

void	convert_to_utf8(t_buf *tbuf, unsigned int c)
{
	if (c >> 16 > 0)
	{
		add_buf(tbuf, c >> 18 | (30 << 3));
		add_buf(tbuf, c << 14 >> 26 | (2 << 6));
		add_buf(tbuf, c << 20 >> 26 | (2 << 6));
		add_buf(tbuf, c << 26 >> 26 | (2 << 6));
	}
	else if (c >> 11 > 0)
	{
		add_buf(tbuf, c >> 12 | (14 << 4));
		add_buf(tbuf, c << 20 >> 26 | (2 << 6));
		add_buf(tbuf, c << 26 >> 26 | (2 << 6));
	}
	else if (c >> 7 > 0)
	{
		add_buf(tbuf, c >> 6 | (6 << 5));
		add_buf(tbuf, c << 26 >> 26 | (2 << 6));
	}
	else
		add_buf(tbuf, c);
}

short	count_utf8_chars(unsigned int c)
{
	if (c >> 21 > 0)
		return (-1);
	else if (c >> 16 > 0)
		return (4);
	else if (c >> 11 > 0)
		return (3);
	else if (c >> 7 > 0)
		return (2);
	else
		return (1);
}

short	print_char_wc(t_one *vault, t_buf *tbuf, unsigned int wc)
{
	wint_t	filler;
	short	char_num;

	filler = ZERO == 1 ? '0' : ' ';
	if ((char_num = count_utf8_chars(wc)) == -1)
		return (-1);
	if (MINUS == 1)
		convert_to_utf8(tbuf, wc);
	while (WIDTH-- - char_num > 0)
		add_buf(tbuf, filler);
	if (MINUS == 0)
		convert_to_utf8(tbuf, wc);
	print_buf(tbuf);
	return (0);
}

short	print_char(t_one *vault, t_va *valist, t_buf *tbuf)
{
	char	c;
	wint_t	wc;

	if (FLAG != 'c' && FLAG != 'C')
		print_char_c(vault, tbuf, FLAG);
	else if (MOD == LONG || FLAG == 'C')
	{
		if (ARG_NUM == 0)
			wc = (wint_t)va_arg(valist->current, wint_t);
		else
			wc = (wint_t)get_va_wchar(vault, valist, (ARG_NUM), 1);
		return (print_char_wc(vault, tbuf, wc));
	}
	else
	{
		if (ARG_NUM == 0)
			c = (char)va_arg(valist->current, int);
		else
			c = (char)get_va_char(vault, valist, (ARG_NUM), 1);
		return (print_char_c(vault, tbuf, c));
	}
	return (0);
}
