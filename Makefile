# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/06/08 07:12:55 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./operation/Makefile
include ./sort_five/Makefile
include ./smart_sort_five_b/t_list_int/Makefile
include ./smart_sort_five_b/Makefile
include ./smart_sort_five_a/Makefile
include ./sort_five_double/Makefile

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = push_swap

SRC += ./push_swap.c \
	   ./setup_struct.c \
	   ./show_stack.c \
	   ./find_pos_max.c \
	   ./find_pos_min.c \
	   ./libft/ft_strlen.c \
	   ./libft/ft_atoi.c \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $^

#clean:
#	rm -f $(OBJ)

fclean: #clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
