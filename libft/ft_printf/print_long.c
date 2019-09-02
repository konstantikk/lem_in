/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:43:53 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:46:23 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	get_unsigned(t_buf *tbuf, t_unum *nums, t_one *vault)
{
	if (MOD == CHAR && FLAG != 'p')
		itoa_base_unsigned((unsigned char)nums->num, nums, vault, tbuf);
	else if ((MOD < INT && MOD != 0) && FLAG != 'p')
		itoa_base_unsigned((unsigned short)nums->num, nums, vault, tbuf);
	else if ((MOD < LONG || MOD == 0) && FLAG != 'p')
		itoa_base_unsigned((unsigned int)nums->num, nums, vault, tbuf);
	else
		itoa_base_unsigned((unsigned long)nums->num, nums, vault, tbuf);
}

static inline void	get_signed(t_buf *tbuf, t_unum *nums, t_one *vault)
{
	if (MOD == CHAR)
		itoa_base_signed((char)nums->num, nums, vault, tbuf);
	else if (MOD == SHORT)
		itoa_base_signed((short)nums->num, nums, vault, tbuf);
	else if (MOD == INT || MOD == 0)
		itoa_base_signed((int)nums->num, nums, vault, tbuf);
	else
		itoa_base_signed((long)nums->num, nums, vault, tbuf);
}

static inline void	set_base(char flag, short *base)
{
	if (flag == 'u')
		*base = 10;
	else if (flag == 'o')
		*base = 8;
	else if (flag == 'x' || flag == 'p' || flag == 'X')
		*base = 16;
	else if (flag == 'b')
		*base = 2;
}

inline void			print_long(t_one *vault, t_va *valist, t_buf *tbuf)
{
	t_unum	nums;

	nums.caps = 0;
	nums.base = 10;
	if (ARG_NUM == 0)
		nums.num = va_arg(valist->current, long);
	else
		nums.num = get_va_long(vault, valist, (ARG_NUM), 1);
	if (FLAG == 'd' || FLAG == 'i')
		get_signed(tbuf, &nums, vault);
	else
	{
		set_base(FLAG, &nums.base);
		if (FLAG == 'X')
			nums.caps = 1;
		get_unsigned(tbuf, &nums, vault);
	}
}
