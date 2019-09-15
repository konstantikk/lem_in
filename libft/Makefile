
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlegros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 16:12:06 by vlegros           #+#    #+#              #
#    Updated: 2019/04/16 23:46:40 by vlegros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
RESOURCES = $(addprefix ./str_funcs/, ft_putchar.c \
    ft_atoi_base.c \
    ft_atoi.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c ) \
	$(addprefix ./char_funcs/, ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_isspace.c ) \
	$(addprefix ./digit_funcs/, ft_itoa.c \
	ft_abs.c) \
	$(addprefix ./lst_funcs/, ft_lst_addback.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c) \
	$(addprefix ./mem_funcs/, ft_bzero.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c) \
	$(addprefix ./useful_funcs/, ft_crt_chmatrix.c \
	ft_find_word.c \
	ft_del_twodem_arr.c \
	ft_swap.c \
	get_next_line.c) \
	$(addprefix ./vec_funcs/, int_vec/ft_int_vec_enlarge.c \
	int_vec/ft_int_vec_pushback.c \
	int_vec/ft_int_vec_pushfront.c \
	int_vec/ft_ivec_init.c \
	int_vec/ft_int_vec_del.c \
	int_vec/ft_int_vec_popfront.c \
	int_vec/ft_int_vec_popback.c \
	ptr_vec/ft_ptr_vec_enlarge.c \
	ptr_vec/ft_ptr_vec_init.c \
	ptr_vec/ft_ptr_vec_pushback.c \
	ptr_vec/ft_ptr_vec_pushfront.c \
	ptr_vec/ft_ptr_vec_popfront.c \
	ptr_vec/ft_ptr_vec_del.c \
	ptr_vec/garbage_collector.c \
	ptr_vec/find_and_del.c \
	ptr_vec/ft_ptr_vec_popback.c \
	char_vec/ft_vec_enlarge.c \
	char_vec/ft_vec_clear.c \
	char_vec/ft_vec_init.c \
	char_vec/ft_chr_vec_pushback.c \
	char_vec/ft_chr_vec_enlarge.c \
	char_vec/ft_chr_vec_del.c \
	char_vec/ft_chr_vec_init.c \
	char_vec/ft_chr_vec_popfront.c) \
	$(addprefix ./ft_printf/, atoi_move.c \
	clean_and_enlarge_vec.c \
	extract_float_values.c \
	fill_helper.c \
	ft_init.c \
	ft_parse.c \
	ft_parse_part_two.c \
	ft_printf.c \
	get_va_arg.c \
	get_va_digit_values.c \
	get_wp.c \
	itoa_base_printf.c \
	long_arithmetic.c \
	print_arg.c \
	print_buf.c \
	print_char.c \
	print_float.c \
	print_long.c \
	print_something.c \
	print_string.c \
	set_precision.c \
	string_helper.c \
	float.c \
	vector_operations.c) \
	$(addprefix ./hashtable/, ft_hash_function.c \
    ft_ht_init.c) \

OBJ = $(RESOURCES:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
%.o: %.c
	gcc $(FLAGS) -Iincludes/ -c $< -o $@ 
clean:
	@rm -f ./char_funcs/*.o ./str_funcs/*.o ./digit_funcs/*.o ./lst_funcs/*.o ./mem_funcs/*.o ./useful_funcs/*.o ./vec_funcs/int_vec/*.o ./vec_funcs/ptr_vec/*.o ./vec_funcs/char_vec/*.o ./ft_printf/*.o ./hashtable/*.o
fclean: clean
	@rm -f $(NAME)
re: fclean all