/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 08:19:43 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:46:56 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	ft_unprint(t_buf *tbuf, int c)
{
	print_buf(tbuf);
	tbuf->count++;
	write(1, "\\", 1);
	ft_printf("%o", c);
}

static void inline	char_to_buf(t_one *vault, t_buf *tbuf, char **str)
{
	if (FLAG == 'r')
		ft_isprint(*(*str)) ?
			add_buf(tbuf, *(*str)++) : ft_unprint(tbuf, *(*str)++);
	else
		add_buf(tbuf, *(*str)++);
}

static void inline	print_string_str(t_one *vault, t_buf *tbuf, char *str)
{
	size_t	char_count;
	size_t	k;

	if (str == NULL)
		str = "(null)";
	char_count = 0;
	while (str[char_count] && char_count < (size_t)PRECISION)
		++char_count;
	k = MINUS == 1 ? 0 : char_count;
	if (MINUS == 1)
	{
		while (k++ < char_count)
			char_to_buf(vault, tbuf, &str);
		fill_width(vault, tbuf, char_count);
	}
	else
	{
		fill_width(vault, tbuf, char_count);
		while (k-- > 0)
			char_to_buf(vault, tbuf, &str);
	}
	print_buf(tbuf);
}

short				print_string_wstr(t_one *vault, t_buf *tbuf, wchar_t *str)
{
	size_t	char_count;
	size_t	len;

	char_count = 0;
	len = get_wstr_len(vault, str);
	if (MINUS == 0)
	{
		fill_width(vault, tbuf, len);
		return (string_to_utf8(vault, tbuf, str));
	}
	if (MINUS == 1)
	{
		string_to_utf8(vault, tbuf, str);
		fill_width(vault, tbuf, len);
	}
	print_buf(tbuf);
	return (0);
}

short				print_string(t_one *vault, t_va *valist, t_buf *tbuf)
{
	char	*str;
	wchar_t	*wstr;

	if (FLAG != 'r' && (MOD == LONG || FLAG == 'S'))
	{
		if (ARG_NUM == 0)
			wstr = va_arg(valist->current, wchar_t*);
		else
			wstr = get_va_wstring(vault, valist, (ARG_NUM), 'l');
		if (wstr != NULL)
			return (print_string_wstr(vault, tbuf, wstr));
		else
			print_string_str(vault, tbuf, (char*)wstr);
	}
	else
	{
		if (ARG_NUM == 0)
			str = va_arg(valist->current, char*);
		else
			str = get_va_string(vault, valist, (ARG_NUM), 0);
		print_string_str(vault, tbuf, str);
	}
	return (0);
}
