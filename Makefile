# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/06/07 06:50:55 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./operation/Makefile
include ./sort_five/Makefile
include ./t_list_int/Makefile

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC += ./push_swap.c \
	   ./setup_struct.c \
	   ./show_stack.c \
	   ./pos_in_stack.c \
	   ./find_pos_max.c \
	   ./libft/ft_strlen.c \
	   ./libft/ft_atoi.c \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $^ -g3 -fsanitize=address

#clean:
#	rm -f $(OBJ)

fclean: #clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
