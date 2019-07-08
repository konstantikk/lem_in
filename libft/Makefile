# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziemann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 23:17:12 by jziemann          #+#    #+#              #
#    Updated: 2019/04/02 21:12:04 by jziemann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)
$(NAME):
	@gcc $(FLAG) -c *.c
	@ar rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all

