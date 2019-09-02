/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:02:17 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 23:04:56 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_width(t_one *vault, char **str, t_va *valist)
{
	char	*tmp;
	long	a;

	if (*++*str >= '0' && **str <= '9')
	{
		tmp = *str;
		a = atoi_move(str);
		if (*(*str)++ == '$')
			WIDTH = -a;
		else
		{
			WIDTH = (int)va_arg(valist->current, int);
			if (WIDTH < 0 && (MINUS = 1))
				WIDTH *= -1;
			*str = tmp;
		}
	}
	else
	{
		WIDTH = (int)va_arg(valist->current, int);
		if (WIDTH < 0 && (MINUS = 1))
			WIDTH *= -1;
	}
}

void	save_width_or_argnum(t_one *vault, char **str)
{
	long a;

	a = atoi_move(str);
	if (**str == '$')
	{
		++*str;
		ARG_NUM = a;
	}
	else
		WIDTH = a;
}

void	modify_if_caps(t_one *vault)
{
	if (FLAG == 'D' || FLAG == 'I' || FLAG == 'O' || FLAG == 'U')
	{
		FLAG = ft_tolower(FLAG);
		MOD = LONG;
	}
}

int		parse_percent(t_one *vault, char **str, t_buf *tbuf, t_va *valist)
{
	while (**str && char_is_flag(*str) != 1)
	{
		find_format(vault, str);
		if (**str == '.')
			save_precision(vault, str, valist);
		else if (**str == '*')
			save_width(vault, str, valist);
		else if (**str >= '1' && **str <= '9')
			save_width_or_argnum(vault, str);
		else if (**str == '$')
			break ;
		else
		{
			find_mod(vault, str);
			++(*str);
		}
	}
	FLAG = **str;
	get_wp_from_args(vault, valist);
	modify_if_caps(vault);
	if (FLAG != 0)
		++*str;
	return (print_arg(vault, valist, tbuf));
}
