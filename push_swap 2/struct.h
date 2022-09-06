/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:03:17 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/06 12:28:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_tli
{
	int				content;
	struct s_tli	*prev;
	struct s_tli	*next;
}	t_tli;

typedef struct s_data
{
	int		*stack_a;
	int		size_a;
	int		*stack_b;
	int		size_b;
}	t_data;

typedef struct s_sub_lst
{
	struct s_sub_lst	*prev;
	struct s_sub_lst	*next;
	int					oper_used;
	int					nb_rra;
	int					*stack_after_oper;
	struct s_sub_lst	*prev_oper;
	struct s_sub_lst	*next_oper;
}	t_sub_lst;

typedef struct s_double_lst
{
	struct s_double_lst	*prev;
	struct s_double_lst	*next;
	t_sub_lst			*sub_lst;
}	t_double_lst;

#endif