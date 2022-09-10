# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/09/08 19:39:25 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./libft/Makefile

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC += ./push_swap.c \

SRC += ./operation_on_tab/sa_ot.c \
	   ./operation_on_tab/ra_ot.c \
	   ./operation_on_tab/rra_ot.c \

SRC += ./operation/sa.c \
	   ./operation/sb.c \
	   ./operation/ss.c \
	   ./operation/pa.c \
	   ./operation/pb.c \
	   ./operation/ra.c \
	   ./operation/rb.c \
	   ./operation/rr.c \
	   ./operation/rra.c \
	   ./operation/rrb.c \
	   ./operation/rrr.c \
	   ./operation/oper_double/od_sa.c \
	   ./operation/oper_double/od_sb.c \
	   ./operation/oper_double/od_pa.c \
	   ./operation/oper_double/od_pb.c \
	   ./operation/oper_double/od_ra.c \
	   ./operation/oper_double/od_rb.c \
	   ./operation/oper_double/od_rra.c \
	   ./operation/oper_double/od_rrb.c \

SRC += ./useful_function/ascending_order_tab.c \
	   ./useful_function/descending_order_tab.c \
	   ./useful_function/dup_tab.c \
	   ./useful_function/pos_in_stack.c \
	   ./useful_function/first_step/setup_struct.c \
	   ./useful_function/first_step/return_error.c \
	   ./useful_function/first_step/ss_cargv_part_two.c \
	   ./useful_function/first_step/check_int_max.c \
	   ./useful_function/first_step/check_int_min.c \
	   ./useful_function/first_step/check_error.c \
	   ./useful_function/first_step/check_repeat.c \

SRC += ./sort_first_five/double_lst/dl_add_back.c \
	   ./sort_first_five/double_lst/dl_last.c \
	   ./sort_first_five/double_lst/dl_new.c \
	   ./sort_first_five/double_lst/sl_add_back.c \
	   ./sort_first_five/double_lst/sl_last.c \
	   ./sort_first_five/double_lst/sl_new.c \
	   ./sort_first_five/double_lst/sl_link.c \
	   ./sort_first_five/double_lst/dl_clear.c \
	   ./sort_first_five/double_lst/sl_int_clear.c \
	   ./sort_first_five/operations_dupp_tab/sa_dt.c \
	   ./sort_first_five/operations_dupp_tab/ra_dt.c \
	   ./sort_first_five/operations_dupp_tab/rra_dt.c \
	   ./sort_first_five/sort_first_five_b/if_sorted_b.c \
	   ./sort_first_five/sort_first_five_b/make_all_oper_b.c \
	   ./sort_first_five/sort_first_five_b/sort_first_five_b.c \
	   ./sort_first_five/sort_ascending_first_five_a/if_sorted_a.c \
	   ./sort_first_five/sort_descending_first_five_a/if_sorted_da.c \
	   ./sort_first_five/sort_ascending_first_five_a/make_all_oper_a.c \
	   ./sort_first_five/sort_descending_first_five_a/make_all_oper_da.c \
	   ./sort_first_five/sort_ascending_first_five_a/sort_first_five_a.c \
	   ./sort_first_five/sort_descending_first_five_a/sort_first_five_da.c \
	   ./sort_first_five/check_duplicate_a.c \
	   ./sort_first_five/check_duplicate_b.c \

SRC += ./t_list_int/tli_new.c \
	   ./t_list_int/tli_setup_a_five.c \
	   ./t_list_int/tli_setup_a_ten.c \
	   ./t_list_int/tli_setup_b_five.c \
	   ./t_list_int/tli_setup_b_ten.c \
	   ./t_list_int/tli_setup_b_half_a.c \
	   ./t_list_int/tli_add_back.c \
	   ./t_list_int/tli_size.c \
	   ./t_list_int/tli_last.c \
	   ./t_list_int/tli_clear.c \
	   ./t_list_int/tli_clear_one.c \
	   ./t_list_int/find_pos_max_tli.c \
	   ./t_list_int/find_pos_min_tli.c \
	   ./t_list_int/tli_setup_b_forty.c \
	   ./t_list_int/tli_setup_a_forty.c \

SRC += ./sort_five_double/sfd_a/sfd_if_sorted_a.c \
	   ./sort_five_double/sfd_a/sfd_make_all_oper_a.c \
	   ./sort_five_double/sfd_a/sfd_sort_first_five_a.c \
	   ./sort_five_double/sfd_b/sfd_if_sorted_b.c \
	   ./sort_five_double/sfd_b/sfd_make_all_oper_b.c \
	   ./sort_five_double/sfd_b/sfd_sort_first_five_b.c \
	   ./sort_five_double/sort_five_double.c \
	   ./sort_five_double/while_for_sfd.c \
	   ./sort_five_double/sfd_da/sfd_if_sorted_da.c \
	   ./sort_five_double/sfd_da/sfd_make_all_oper_da.c \
	   ./sort_five_double/sfd_da/sfd_sort_first_five_da.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
