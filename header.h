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

typedef struct s_tab
{
	int				*content;
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
t_tab	*ft_lst_tab_new(int *content);
t_tab	*ft_lst_tab_last(t_tab *lst);
void	ft_lst_tab_add_back(t_tab **lst, t_tab *new);
int		ft_lst_tab_size(t_tab *lst);
void	ft_lst_tab_clear(t_tab **lst);

#endif