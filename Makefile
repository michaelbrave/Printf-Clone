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

NAME = libftprintf

HEAD = ft_printf.h

GCC = gcc

FLAGS = -g -Wall -Wextra -Werror

LIBFLAGS = -L./libft -lft

LIBFT = libft

LIB = libft.a

SRC = 
	main.c, 
	ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(GCC) $(FLAGS) -c $(SRC) -I $(LIBFT)
	$(GCC) -o $(NAME) $(OBJ) $(LIBFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm