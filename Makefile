# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:46:52 by mbrave            #+#    #+#              #
#    Updated: 2019/06/25 14:46:55 by mbrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

#-Wall -Wextra -Werror /add back to cflags later
CFLAGS = -g -I includes/ -I $(LIBFT)

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
	do_percent.c \
	printprint.c \
	length.c \
	length2.c \
	formaters.c \
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