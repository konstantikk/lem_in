/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:35:59 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/15 19:41:46 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

void	fill_width_with_spaces(t_one *vault, t_buf *tbuf, size_t len, char elem)
{
	size_t	i;

	i = 0;
	while (len + i < (size_t)WIDTH)
	{
		add_buf(tbuf, elem);
		i++;
	}
}

void	edit_output(char *str, t_one *vault, t_buf *tbuf, long char_count)
{
	long index;

	index = 0;
	if (MINUS)
	{
		while (index < char_count)
			add_buf(tbuf, str[index++]);
		if (!ZERO)
			fill_width_with_spaces(vault, tbuf, char_count, ' ');
		else if (ft_strchr(str, 'n') || ft_strchr(str, 'N') ||
				ft_strchr(str, 'i') || ft_strchr(str, 'I'))
			fill_width_with_spaces(vault, tbuf, char_count, ' ');
	}
	else
	{
		if (!ZERO)
			fill_width_with_spaces(vault, tbuf, char_count, ' ');
		else if (ft_strchr(str, 'n') || ft_strchr(str, 'N') ||
				ft_strchr(str, 'i') || ft_strchr(str, 'I'))
			fill_width_with_spaces(vault, tbuf, char_count, ' ');
		while (index < char_count)
			add_buf(tbuf, str[index++]);
	}
	ft_strdel(&str);
}

void	print_float(t_one *vault, t_va *valist, t_buf *tbuf)
{
	long double	value;
	char		*str;

	if (ARG_NUM == 0)
		value = MODL ? va_arg(valist->current, long double) :
	va_arg(valist->current, double);
	else
		value = MODL ? get_va_long_double(vault, valist, (ARG_NUM), 1) :
			get_va_double(vault, valist, (ARG_NUM), 1);
	if (!(str = ft_ftoa(value, vault)))
		return ;
	if (!PLUS && !ft_strchr(str, '-') &&
			str[0] != 'n' && str[0] != 'N' && SPACE)
	{
		add_buf(tbuf, ' ');
		WIDTH = WIDTH ? --WIDTH : 0;
	}
	edit_output(str, vault, tbuf, ft_strlen(str));
}
