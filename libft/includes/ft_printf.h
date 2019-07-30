/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:34:30 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 23:41:11 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <unistd.h>

# define PRINTF_BUF	1000
# define MAX_ARGS	100
# define PSTARTING	(-1 * MAX_ARGS - 1)
# define PRECISION	vault->precision
# define WIDTH		vault->width
# define ZERO		vault->zero
# define MINUS		vault->minus
# define PLUS		vault->plus
# define MOD		vault->mod
# define MODL		vault->modl
# define HASH		vault->hash
# define SPACE		vault->space
# define FLAG		vault->flag
# define ARG_NUM	vault->arg_num

# define COLOR		1

# define RED 	"\033[0;91m"
# define RED_LEN	3

# define GREEN	"\033[0;92m"
# define GREEN_LEN	5

# define YELLOW	"\033[0;93m"
# define YELLOW_LEN	6

# define BLUE	"\033[0;96m"
# define BLUE_LEN	4

# define GREY	"\033[0;10m"
# define GREY_LEN	4

typedef struct	s_unum
{
	size_t		num;
	short		base;
	short		caps;
}				t_unum;

typedef enum	e_type
{
	CHAR = 1,
	SHORT,
	USHORT,
	INT,
	UINT,
	LONG,
	LONGLONG,
	ULONG,
	FLOAT,
	DOUBLE,
	STR,
	LDOUBLE
}				t_type;

typedef struct	s_va
{
	va_list		start;
	va_list		current;
}				t_va;

typedef struct	s_buf
{
	char		*buf;
	int			i;
	int			count;
}				t_buf;

typedef struct	s_one
{
	t_type		arg_arr[MAX_ARGS];
	long		precision;
	long		width;
	short		modl;
	t_type		mod;
	short		minus;
	short		plus;
	short		zero;
	short		hash;
	short		space;
	short		arg_num;
	char		flag;
}				t_one;

typedef struct	s_dict
{
	char		c;
	void		(*ft)(t_one, char);
}				t_dict;

void			print_vault(t_one *vault);
void			print_args(t_one *vault);
int				ft_printf(const char *restrict format, ...);
void			ft_vault_null(t_one *vault);
int				parse_percent(t_one *vault, char **str, t_buf *tbuf,
				t_va *valist);
void			print_buf(t_buf *tbuf);
void			get_wp_from_args(t_one *vault, t_va *valist);
long			atoi_move(char **str);
int				char_is_flag(char *c);
void			get_arg_types(t_one *vault, char *str);
short			print_arg(t_one *vault, t_va *valist, t_buf *tbuf);
void			arg_arr_init(t_one *vault);
void			go_to_arg(t_one *vault, va_list tmp, int a);
char			get_va_char(t_one *vault, t_va *valist, int arg_num,
				short move_current);
wint_t			get_va_wchar(t_one *vault, t_va *valist, int arg_num,
				short move_current);
char			*get_va_string(t_one *vault, t_va *valist, int arg_num,
				short move_current);
wchar_t			*get_va_wstring(t_one *vault, t_va *valist, int arg_num,
				short move_current);
long			get_va_long(t_one *vault, t_va *valist, int arg_num,
				short move_current);
long double		get_va_long_double(t_one *vault, t_va *valist,
				int arg_num, short move_current);
double			get_va_double(t_one *vault, t_va *valist, int arg_num,
				short move_current);
void			go_to_arg(t_one *vault, va_list tmp, int arg_num);
char			get_va_char(t_one *vault, t_va *valist, int arg_num,
				short move_current);
wint_t			get_va_wchar(t_one *vault, t_va *valist, int arg_num,
				short move_current);
char			*get_va_string(t_one *vault, t_va *valist, int arg_num,
				short move_current);
wchar_t			*get_va_wstring(t_one *vault, t_va *valist, int arg_num,
				short move_current);
long			get_va_long(t_one *vault, t_va *valist, int arg_num,
				short move_current);
long double		get_va_long_double(t_one *vault, t_va *valist, int arg_num,
				short move_current);
double			get_va_double(t_one *vault, t_va *valist, int arg_num,
				short move_current);
short			print_char(t_one *vault, t_va *valist, t_buf *tbuf);
short			print_string(t_one *vault, t_va *valist, t_buf *tbuf);
void			print_float(t_one *vault, t_va *valist, t_buf *tbuf);
short			count_to_utf8(t_buf *tbuf, unsigned int c);
void			add_buf(t_buf *tbuf, char c);
void			itoa_base_unsigned(size_t num, t_unum *nums, t_one *vault,
				t_buf *tbuf);
void			print_long(t_one *vault, t_va *valist, t_buf *tbuf);
void			itoa_base_signed(long num_in, t_unum *nums, t_one *vault,
				t_buf *tbuf);
short			count_utf8_chars(unsigned int c);
void			convert_to_utf8(t_buf *tbuf, unsigned int c);
void			save_precision(t_one *vault, char **str, t_va *valist);
int				find_format(t_one *vault, char **str);
void			find_mod(t_one *vault, char **str);
int				char_is_flag(char *c);
void			fill_width(t_one *vault, t_buf *tbuf, size_t len);
short			string_to_utf8(t_one *vault, t_buf *tbuf, wchar_t *str);
size_t			get_wstr_len(t_one *vault, wchar_t *str);
void			apply_hash(t_one *vault, t_buf *tbuf, size_t num,
				short *chars_number);
void			select_sign(t_one *vault, t_buf *tbuf, long num);
void			fill_num_width(t_one *vault, t_buf *tbuf,
				short *chars_number, short sign);
void			fill_num_precision(t_one *vault, t_buf *tbuf,
				short *chars_number);
void			fill_buf(t_buf *tbuf, char a, size_t len);
#endif
