/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/20 10:26:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	if_sorted_two(t_sub_lst *cpy, t_sub_lst *lst_oper);
static void	if_sorted_three(t_data *d, t_sub_lst *cpy_lo);

int	if_sorted_a(t_data *d, t_sub_lst *copy_sl)
{
	t_sub_lst	*cpy;
	t_sub_lst	*lst_oper;
	t_sub_lst	*cpy_lo;
	int			ascending_order_size;
	int			aot;

	if (d->size_a >= 5)
		ascending_order_size = 5;
	else
		ascending_order_size = d->size_a;
	cpy = copy_sl;
	lst_oper = sl_new(0, NULL, 0);
	aot = ascending_order_tab(copy_sl->stack_after_oper, ascending_order_size);
	if (aot == -1 && (copy_sl->nb_rra == 0 || d->size_a <= 5))
	{
		if_sorted_two(cpy, lst_oper);
		cpy_lo = lst_oper;
		if_sorted_three(d, cpy_lo);
		sl_int_clear(&lst_oper);
		return (1);
	}
	sl_int_clear(&lst_oper);
	return (0);
}

static void	if_sorted_two(t_sub_lst *cpy, t_sub_lst *lst_oper)
{
	while (cpy->prev_oper)
	{
		sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
		cpy = cpy->prev_oper;
	}
	sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
}

static void	if_sorted_three(t_data *d, t_sub_lst *cpy_lo)
{
	while (cpy_lo->next)
		cpy_lo = cpy_lo->next;
	while (cpy_lo->prev)
	{
		if (cpy_lo->oper_used == 1)
			sa(d);
		if (cpy_lo->oper_used == 2)
			ra(d);
		if (cpy_lo->oper_used == 4)
			rra(d);
		cpy_lo = cpy_lo->prev;
	}
}
