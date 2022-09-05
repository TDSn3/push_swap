/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/20 10:05:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	next_to_sa(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_ra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_rra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);

void	make_all_oper(t_double_lst *dl, t_data *d, int i)
{
	t_sub_lst	*copy_sl;

	copy_sl = (dl_last(dl))->sub_lst;
	dl_add_back(&dl, dl_new());
	while (copy_sl)
	{
		if (if_sorted(d, copy_sl))
			return ;
		if (copy_sl->oper_used == 1)
			next_to_sa(d, dl, copy_sl);
		if (copy_sl->oper_used == 2)
			next_to_ra(d, dl, copy_sl);
		if (copy_sl->oper_used == 4)
			next_to_rra(d, dl, copy_sl);
		copy_sl = copy_sl->next;
	}
	i++;
	make_all_oper(dl, d, i);
}

static void	next_to_sa(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;

	if (!check_duplicate_a(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	if (!check_duplicate_a(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}	
}

static void	next_to_ra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;

	if (!check_duplicate_a(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	if (!check_duplicate_a(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}	
}

static void	next_to_rra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;

	if (!check_duplicate_a(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	if (!check_duplicate_a(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_a)))
	{
		nsl = sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a), 0);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}	
}
