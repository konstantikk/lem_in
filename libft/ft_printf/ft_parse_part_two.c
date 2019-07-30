/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_part_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:20:34 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/16 21:42:24 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_is_flag(char *c)
{
	if (*c <= 32 || *c == 127 || *c == 39 || (*c >= '*' && *c <= '.') ||
		(*c >= '0' && *c <= '9') || *c == 'l' || *c == 'h' || *c == 'L' ||
		*c == 'j' || *c == 't' || *c == 'z' || *c == '#' ||
		(*c == '$' && (*(c - 1) == '*' || *(c - 1) >= '0' || *(c - 1) <= '9')))
		return (0);
	else
		return (1);
}

void		find_mod(t_one *vault, char **str)
{
	if ((MOD < SHORT) && **str == 'h')
		MOD = SHORT;
	else if (MOD == SHORT && **str == 'h')
		MOD = CHAR;
	else if ((MOD < LONG || MOD == LONGLONG) && **str == 'l')
		MOD = LONG;
	else if (MOD == LONG && **str == 'l')
		MOD = LONGLONG;
	else if (MOD <= ULONG && (**str == 'j' || **str == 't' || **str == 'z'))
		MOD = LONGLONG;
	else if (**str == 'L')
		MODL = 1;
}

int			find_format(t_one *vault, char **str)
{
	if (**str == '0' && (*(*str - 1) <= '0' || *(*str - 1) > '9'))
		ZERO = 1;
	else if (**str == '-')
		MINUS = 1;
	else if (**str == '+')
		PLUS = 1;
	else if (**str == '#')
		HASH = 1;
	else if (**str == ' ')
		SPACE = 1;
	else
		return (0);
	return (1);
}

void		save_precision(t_one *vault, char **str, t_va *valist)
{
	char	*tmp;
	long	a;

	if (*++*str == '*')
	{
		tmp = ++*str;
		if (**str >= '0' && **str <= '9')
		{
			a = atoi_move(str);
			if (*++*str == '$')
				PRECISION = -a;
		}
		else
		{
			PRECISION = (int)va_arg(valist->current, int);
			PRECISION = PRECISION < 0 ? PSTARTING : PRECISION;
			*str = tmp;
		}
	}
	else
		PRECISION = atoi_move(str);
}
