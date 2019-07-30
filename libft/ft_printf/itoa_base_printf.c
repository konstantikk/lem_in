/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:47:27 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 21:44:44 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				one_char(short num, short base, short caps)
{
	char	c;

	if (base <= 10)
		c = num + '0';
	else
	{
		if (num < 10)
			c = num + '0';
		else
		{
			if (caps == 0)
				c = num + 'a' - 10;
			else
				c = num + 'A' - 10;
		}
	}
	return (c);
}

void				fill_buf(t_buf *tbuf, char a, size_t len)
{
	size_t i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
		{
			add_buf(tbuf, a);
			++i;
		}
	}
}

static inline void	thanks_norme(t_one *vault, t_unum *nums, size_t tmp,
					t_buf *tbuf)
{
	if (nums->num == 0 && PRECISION == 0)
		return ;
	while (tmp >= 1)
	{
		add_buf(tbuf, one_char(nums->num / tmp, nums->base, nums->caps));
		nums->num %= tmp;
		tmp /= nums->base;
	}
}

void				itoa_base_unsigned(size_t num, t_unum *nums, t_one *vault,
		t_buf *tbuf)
{
	size_t			tmp;
	short			chars_number;
	short			sign;

	chars_number = (num == 0 && PRECISION == 0) ? 0 : 1;
	sign = 0;
	if (FLAG == 'p' || (HASH == 1 && FLAG != 'u' && FLAG != 'o' && num != 0))
		sign = 2;
	tmp = 1;
	while (tmp * nums->base / nums->base == tmp &&
			(tmp * nums->base) <= num && ++chars_number)
		tmp *= nums->base;
	if (MINUS == 0)
		fill_num_width(vault, tbuf, &chars_number, sign);
	if (((FLAG == 'p' && HASH != 3) || (FLAG != 'p' && HASH == 1)))
		apply_hash(vault, tbuf, num, &chars_number);
	fill_num_precision(vault, tbuf, &chars_number);
	nums->num = num;
	thanks_norme(vault, nums, tmp, tbuf);
	if (MINUS != 0)
		fill_num_width(vault, tbuf, &chars_number, sign);
	print_buf(tbuf);
}

void				itoa_base_signed(long num_in, t_unum *nums, t_one *vault,
					t_buf *tbuf)
{
	size_t			tmp;
	short			chars_number;
	short			sign;

	chars_number = (num_in == 0 && PRECISION == 0) ? 0 : 1;
	sign = 0;
	tmp = 1;
	if (num_in < 0 || SPACE == 1 || PLUS == 1)
		sign = 1;
	nums->num = num_in < 0 ? (unsigned long)-(num_in + 1) + 1 : num_in;
	while (tmp * nums->base / nums->base == tmp &&
			(unsigned long)(tmp * nums->base) <= nums->num && ++chars_number)
		tmp *= nums->base;
	if (MINUS == 0 && ZERO == 1 && PRECISION < 0)
		select_sign(vault, tbuf, num_in);
	if (MINUS == 0)
		fill_num_width(vault, tbuf, &chars_number, sign);
	if (ZERO == 0 || PRECISION >= 0)
		select_sign(vault, tbuf, num_in);
	fill_num_precision(vault, tbuf, &chars_number);
	thanks_norme(vault, nums, tmp, tbuf);
	if (MINUS != 0)
		fill_num_width(vault, tbuf, &chars_number, sign);
	print_buf(tbuf);
}
