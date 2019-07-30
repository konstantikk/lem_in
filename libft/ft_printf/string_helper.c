/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:18:50 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:47:11 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_width(t_one *vault, t_buf *tbuf, size_t len)
{
	size_t	i;
	char	c;

	i = 0;
	c = ZERO == 1 ? '0' : ' ';
	while (len + i < (size_t)WIDTH)
	{
		add_buf(tbuf, c);
		i++;
	}
}

short			string_to_utf8(t_one *vault, t_buf *tbuf, wchar_t *str)
{
	size_t	i;
	short	k;
	long	len;

	i = 0;
	len = 0;
	k = 0;
	while (str[i] && PRECISION == PSTARTING)
	{
		if (count_utf8_chars(str[i]) == -1)
			return (-1);
		convert_to_utf8(tbuf, str[i]);
		i++;
	}
	while (str[i] && PRECISION >= 0 && len < PRECISION)
	{
		if ((k = count_utf8_chars(str[i])) == -1)
			return (-1);
		convert_to_utf8(tbuf, str[i]);
		i++;
		len += k;
	}
	if (len > PRECISION)
		tbuf->i -= k;
	return (0);
}

size_t			get_wstr_len(t_one *vault, wchar_t *str)
{
	size_t	i;
	size_t	count;
	size_t	tmp;

	count = 0;
	i = 0;
	while (str[i])
	{
		tmp = count;
		if (str[i] >> 21 > 0)
			return (0);
		else if (str[i] >> 16 > 0)
			count += 4;
		else if (str[i] >> 11 > 0)
			count += 3;
		else if (str[i] >> 7 > 0)
			count += 2;
		else
			count += 1;
		if ((long)count > PRECISION && PRECISION != PSTARTING)
			return (tmp);
		i++;
	}
	return (count);
}
