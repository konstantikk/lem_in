/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:41:52 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:42:42 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exit(t_va *valist, t_buf *tbuf)
{
	va_end(valist->start);
	va_end(valist->current);
	return (tbuf->count);
}

int		paint_output(char **str, t_buf *tbuf, char *color, int len)
{
	if (*str + 1 + len && *(*str + 1 + len) == '}')
	{
		print_buf(tbuf);
		write(1, color, 7);
		*str = ++*str + len + 1;
		return (1);
	}
	return (0);
}

int		check_color(char **str, t_buf *tbuf)
{
	if (!ft_strncmp("RED", *str + 1, RED_LEN))
		return (paint_output(str, tbuf, RED, RED_LEN));
	else if (!ft_strncmp("GREEN", *str + 1, GREEN_LEN))
		return (paint_output(str, tbuf, GREEN, GREEN_LEN));
	else if (!ft_strncmp("YELLOW", *str + 1, YELLOW_LEN))
		return (paint_output(str, tbuf, YELLOW, YELLOW_LEN));
	else if (!ft_strncmp("BLUE", *str + 1, BLUE_LEN))
		return (paint_output(str, tbuf, BLUE, BLUE_LEN));
	else if (!ft_strncmp("GREY", *str + 1, GREY_LEN))
		return (paint_output(str, tbuf, GREY, GREY_LEN));
	return (0);
}

int		parse_till_percent(char **str, t_buf *tbuf)
{
	while (**str)
	{
		if (!(COLOR && **str == '{' && check_color(str, tbuf)))
		{
			if (**str == '%')
			{
				++(*str);
				return (1);
			}
			add_buf(tbuf, *(*str)++);
			if (tbuf->i == PRINTF_BUF)
				print_buf(tbuf);
		}
	}
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	t_one			vault;
	t_buf			tbuf;
	char			buf[PRINTF_BUF];
	char			*str;
	t_va			valist;

	if (!format)
		return (-1);
	va_start(valist.start, format);
	va_copy(valist.current, valist.start);
	str = (char*)format;
	tbuf.buf = buf;
	tbuf.i = 0;
	tbuf.count = 0;
	arg_arr_init(&vault);
	get_arg_types(&vault, str);
	while (*str)
	{
		ft_vault_null(&vault);
		if (parse_till_percent(&str, &tbuf) == 1)
			if (parse_percent(&vault, &str, &tbuf, &valist) == -1)
				return (ft_exit(&valist, &tbuf));
	}
	print_buf(&tbuf);
	return (ft_exit(&valist, &tbuf));
}
