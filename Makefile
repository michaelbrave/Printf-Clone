# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:46:52 by mbrave            #+#    #+#              #
#    Updated: 2019/09/26 04:03:56 by mbrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -I includes/ -I $(LIBFT)

LDFLAGS = -L. -lftprintf

LIBFT = ./src/libft/

SRC = ft_printf.c \
	initializers.c \
	parsers.c \
	print_or_parse.c \
	switch_do.c \
	do_c.c \
	do_d.c \
	do_o.c \
	do_p.c \
	do_s.c \
	do_u.c \
	do_x.c \
	do_f.c \
	length.c \
	do_percent.c \
	make_int.c \
	make_short.c \
	make_char.c \
	make_long.c \
	make_long_long.c \
	formaters.c \
	width_precision.c \
	printprint.c \
	cleanclean.c \

OBJ = $(patsubst %.c,src/%.o,$(SRC))

all: $(NAME)

libft:
	make -C $(LIBFT)

$(NAME): libft $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBFT)*.o

test: all
	$(CC) $(CFLAGS) main.c $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re norm libft
