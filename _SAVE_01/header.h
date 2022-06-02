/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_sub_lst
{
	struct s_sub_lst	*prev;
	struct s_sub_lst	*next;
	int					oper_used;
	int					*stack_after_oper;
	struct s_sub_lst	*prev_oper;
	struct s_sub_lst	*next_oper;
}	t_sub_lst;

typedef	struct s_double_lst
{
	struct s_double_lst	*prev;
	struct s_double_lst	*next;
	t_sub_lst			*sub_lst;
}	t_double_lst;


typedef struct s_tab
{
	int				*content;
	int				pos;
	struct s_tab	*next;
}	t_tab;

typedef struct s_data
{
	int		*stack_a;
	int		*copy_stack_a;
	int		size_a;
	int		*stack_b;
	int		*copy_stack_b;
	int		size_b;
	int		recu_on;
	int		stock_recu_i;
	t_tab	*lst_copy_stack;
	t_sub_lst	*find;
}	t_data;


void    sa(t_data *d);
void    sb(t_data *d);
void    ss(t_data **d);
void    pa(t_data *d);
void    pb(t_data *d);
void    ra(t_data *d);
void    rb(t_data *d);
void    rr(t_data **d);
void    rra(t_data *d);
void    rrb(t_data *d);
void    rrr(t_data **d);
int		setup_struct(t_data *d, int argc, char **argv);
int		ascending_order_a(t_data d);
int		ascending_order_b(t_data d);
int		find_max_a(t_data d);
t_tab	*ft_lst_tab_new(int *content, int pos);
t_tab	*ft_lst_tab_last(t_tab *lst);
void	ft_lst_tab_add_back(t_tab **lst, t_tab *new);
int		ft_lst_tab_size(t_tab *lst);
void	ft_lst_tab_clear(t_tab **lst);
int		*dup_tab(int *tab, int size);

t_double_lst	*dl_new();
t_sub_lst		*sl_new(int oper_used, int *stack_after_oper);
t_double_lst	*dl_last(t_double_lst *dl);
t_sub_lst		*sl_last(t_sub_lst *sl);
void			dl_add_back(t_double_lst **dl, t_double_lst *new_dl);
void			sl_add_back(t_sub_lst **sl, t_sub_lst *new_sl);
void			sl_link(t_sub_lst *sl, t_sub_lst *sl_prev);

int		*sa_ot(int *tab, int size);
int		*ra_ot(int *tab, int size);
int		*rra_ot(int *tab, int size);

int		*sa_dt(int *tab, int size);
int		*ra_dt(int *tab, int size);
int		*rra_dt(int *tab, int size);

void	make_all_oper(t_double_lst *dl, t_data *d, int i);
int 	ascending_order_tab(int *tab, int size);

#endif