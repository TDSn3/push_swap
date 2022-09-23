/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/23 10:43:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	is_two(t_data *d, t_sub_lst *cy, t_sub_lst *l_o, t_double_lst **dl);
static void	if_sorted_three(t_data *d, t_sub_lst *cy_lo);
static void	part_two(t_data *d, int *ao_sz, t_sub_lst **cy, t_sub_lst *copy_sl);

int	if_sorted_a(t_data *d, t_sub_lst *copy_sl, t_double_lst **dl)
{
	t_sub_lst	*cy;
	t_sub_lst	*l_o;
	t_sub_lst	*cy_lo;
	int			ao_sz;
	int			aot;

	part_two(d, &ao_sz, &cy, copy_sl);
	l_o = NULL;
	l_o = sl_new(0, NULL, 0);
	if (!l_o)
	{
		clear_all(d);
		exit (-1);
	}
	aot = ascending_order_tab(copy_sl->stack_after_oper, ao_sz);
	if (aot == -1 && (copy_sl->nb_rra == 0 || d->size_a <= 5))
	{
		is_two(d, cy, l_o, dl);
		cy_lo = l_o;
		if_sorted_three(d, cy_lo);
		sl_int_clear(&l_o);
		return (1);
	}
	sl_int_clear(&l_o);
	return (0);
}

static void	is_two(t_data *d, t_sub_lst *cy, t_sub_lst *l_o, t_double_lst **dl)
{
	while (cy->prev_oper)
	{
		if (sl_add_back(&l_o, sl_new(cy->oper_used, NULL, 0)))
		{
			dl_clear(dl);
			sl_int_clear(&l_o);
			clear_all(d);
			exit (-1);
		}
		cy = cy->prev_oper;
	}
	if (sl_add_back(&l_o, sl_new(cy->oper_used, NULL, 0)))
	{
		dl_clear(dl);
		sl_int_clear(&l_o);
		clear_all(d);
		exit (-1);
	}
}

static void	if_sorted_three(t_data *d, t_sub_lst *cy_lo)
{
	while (cy_lo->next)
		cy_lo = cy_lo->next;
	while (cy_lo->prev)
	{
		if (cy_lo->oper_used == 1)
			sa(d);
		if (cy_lo->oper_used == 2)
			ra(d);
		if (cy_lo->oper_used == 4)
			rra(d);
		cy_lo = cy_lo->prev;
	}
}

static void	part_two(t_data *d, int *ao_sz, t_sub_lst **cy, t_sub_lst *copy_sl)
{
	if (d->size_a >= 5)
		*ao_sz = 5;
	else
		*ao_sz = d->size_a;
	*cy = copy_sl;
}
