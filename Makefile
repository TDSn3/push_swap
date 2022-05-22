# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/04/02 13:16:00 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = ./push_swap.c \
	  ./setup_struct.c \
	  ./ascending_order_a.c \
	  ./ascending_order_b.c \
	  ./find_max_a.c \
	  ./operations/sa.c \
	  ./operations/sb.c \
	  ./operations/ss.c \
	  ./operations/pa.c \
	  ./operations/pb.c \
	  ./operations/ra.c \
	  ./operations/rb.c \
	  ./operations/rr.c \
	  ./operations/rra.c \
	  ./operations/rrb.c \
	  ./operations/rrr.c \
	  ./libft/ft_strlen.c \
	  ./libft/ft_atoi.c \
	  ./ft_lst_tab_new.c \
	  ./ft_lst_tab_last.c \
	  ./ft_lst_tab_add_back.c \
	  ./ft_lst_tab_size.c \
	  ./ft_lst_tab_clear.c \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $^

#clean:
#	rm -f $(OBJ)

fclean: #clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
