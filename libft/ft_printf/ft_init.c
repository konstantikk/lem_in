/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:15:05 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:41:55 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vault_null(t_one *vault)
{
	ZERO = 0;
	PLUS = 0;
	MINUS = 0;
	HASH = 0;
	SPACE = 0;
	MOD = 0;
	FLAG = 0;
	PRECISION = PSTARTING;
	WIDTH = 0;
	MODL = 0;
	ARG_NUM = 0;
}

void	arg_arr_init(t_one *vault)
{
	int i;

	i = 0;
	while (i < MAX_ARGS)
	{
		vault->arg_arr[i] = 0;
		++i;
	}
}

void	type_to_arr(t_one *vault, char c, int i, int l)
{
	if (i < 0)
		return ;
	if (c == 'f' || c == 'F')
		vault->arg_arr[i] = l == 1 ? LDOUBLE : FLOAT;
	else
		vault->arg_arr[i] = LONG;
}

char	*get_var_type(t_one *vault, char **str)
{
	int l;
	int i;
	int a;

	i = 0;
	l = 0;
	a = 0;
	while (char_is_flag(++(*str)) != 1)
	{
		if (*(*str) == 'L')
			l = 1;
		if (*(*str) >= '0' && *(*str) <= '9')
		{
			if (*((*str) - 1) != '*' && *((*str) - 1) != '.')
				a = atoi_move(str);
			if (*(*str) == '$')
				i = a - 1;
		}
	}
	type_to_arr(vault, *(*str), i, l);
	return (*str);
}

void	get_arg_types(t_one *vault, char *str)
{
	while (*str)
	{
		if (*str == '%')
			str = get_var_type(vault, &str);
		else
			++str;
	}
}
