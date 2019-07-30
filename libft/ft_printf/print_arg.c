/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 05:14:32 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:45:13 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"

short	print_arg(t_one *vault, t_va *valist, t_buf *tbuf)
{
	const char ints[] = "diouxDIOUXpb";
	const char floats[] = "fFeEgG";

	if (FLAG == 'p')
		HASH = 1;
	if (FLAG == 0)
		print_buf(tbuf);
	else if (FLAG == 's' || FLAG == 'S' || FLAG == 'r')
		return (print_string(vault, valist, tbuf));
	else if (ft_strchr(ints, FLAG))
		print_long(vault, valist, tbuf);
	else if (ft_strchr(floats, FLAG))
		print_float(vault, valist, tbuf);
	else
		return (print_char(vault, valist, tbuf));
	return (0);
}
