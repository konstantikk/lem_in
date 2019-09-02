/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:22:07 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/16 23:42:00 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_FLOAT_H
# define FLOAT_FLOAT_H

# include "libft.h"
# include "ft_printf.h"

# define DATA(vec, index) ((char*)(vec->data))[index]
# define EXPONENT_MAX (short)32767
# define FRACTION_MAX 0x8000000000000000

typedef struct	s_parsed_float
{
	unsigned long	fraction;
	unsigned		exponent:15;
	unsigned		sign:1;
}				t_parsed_float;

typedef union	u_float
{
	long double		value;
	t_parsed_float	parsed_float;
}				t_float;

void			vec_del(t_vec **vec);
char			*ft_strrev(char *str);
int				vec_pushback(t_vec *vec, char c, long n);
int				vec_pushfront(t_vec *vec, char c, long n);
int				vec_insert(t_vec *vec, char c, long n, long place);
int				vec_enlarge(t_vec *vec, long n);
int				vec_popfront(t_vec *vec, long n);
int				take_exponent_and_fraction(long double *value, short *exponent,
									unsigned long *fraction, unsigned *sign);
t_vec			*utoa(unsigned long fraction);
char			*ft_ftoa(long double value, t_one *vault);
char			*calculations(t_vec *frac, short exponent, unsigned sign,
															t_one *vault);
char			*inf_nan_check(unsigned long fraction, unsigned sign,
															t_one *vault);
void			fill_width(t_one *vault, t_buf *tbuf, size_t len);
t_vec			*set_precision(t_vec *result, short exponent, t_one *vault);
t_vec			*fast_long_pow(t_vec *result, short power);

#endif
