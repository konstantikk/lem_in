/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_something.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 01:40:33 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:46:41 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_vault(t_one *vault)
{
	printf("zero:\t\t%d\nminus:\t\t%d\nplus:\t\t%d\nhash:\t\t%d\nspace:\t\t%d\n\
			mod:\t\t%d\nflag:\t\t%c\nprecision:\t%ld\nwidth\t\t%ld\nmodl:\t\t%d\
			\narg_num:\t%d\n",
			ZERO, MINUS, PLUS, HASH, SPACE, MOD, FLAG, PRECISION, WIDTH, MODL,
			ARG_NUM);
}

void	print_args(t_one *vault)
{
	int i;

	i = 0;
	while (i < 100)
	{
		printf("%d: %d\n", i, vault->arg_arr[i]);
		++i;
	}
}
