/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 01:03:51 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:43:00 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_to_arg(t_one *vault, va_list tmp, int arg_num)
{
	int		k;

	k = 0;
	while (k < arg_num)
	{
		if (vault->arg_arr[k] == 12)
			va_arg(tmp, long double);
		else if (vault->arg_arr[k] == FLOAT)
			va_arg(tmp, double);
		else
			va_arg(tmp, long);
		++k;
	}
}

/*
** move_current = 1 for MOVING ARGUMENTS ONLY, NOT FOR WIDTH AND PRECISION
*/

char	get_va_char(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list tmp;
	char	c;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	c = (char)va_arg(tmp, int);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (c);
}

wint_t	get_va_wchar(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list tmp;
	wint_t	wc;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	wc = (wint_t)va_arg(tmp, wint_t);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (wc);
}

char	*get_va_string(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list tmp;
	char	*s;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	s = va_arg(tmp, char*);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (s);
}

wchar_t	*get_va_wstring(t_one *vault, t_va *valist, int arg_num,
		short move_current)
{
	va_list tmp;
	wchar_t	*ws;

	va_copy(tmp, valist->start);
	go_to_arg(vault, tmp, arg_num - 1);
	ws = va_arg(tmp, wchar_t*);
	if (move_current == 1)
	{
		va_end(valist->current);
		va_copy(valist->current, tmp);
	}
	va_end(tmp);
	return (ws);
}
