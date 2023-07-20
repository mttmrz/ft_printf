# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 19:38:56 by mmarzano          #+#    #+#              #
#    Updated: 2022/11/10 19:38:59 by mmarzano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_core.c ft_printf_flg.c ft_printf_flg_core.c \
	  ft_printf_flg_printer.c ft_printf_flg_printer2.c ft_printf_flg_printer_core.c \
	  ft_printf_flg_printer_core2.c ft_printf_flg_utils.c ft_printf_simple.c ft_printf_simple_printer.c \
	  ft_printf_utils.c ft_printf_utils2.c ft_main.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

bonus: all

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS)

.PHONY: all bonus clean fclean re
