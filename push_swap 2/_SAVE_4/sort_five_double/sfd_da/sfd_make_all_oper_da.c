/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfd_make_all_oper_da.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:30:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/08 19:31:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	next_to_sa(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_ra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_rra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);

void	sfd_make_all_oper_da(t_double_lst *dl, t_data *d, t_sub_lst **lst_oper)
{
	t_sub_lst	*copy_sl;

	copy_sl = (dl_last(dl))->sub_lst;
	dl_add_back(&dl, dl_new());
	while (copy_sl)
	{	
		if (sfd_if_sorted_da(d, copy_sl, lst_oper))
			return ;
		if (copy_sl->oper_used == 1)
			next_to_sa(d, dl, copy_sl);
		if (copy_sl->oper_used == 2)
			next_to_ra(d, dl, copy_sl);
		if (copy_sl->oper_used == 4)
			next_to_rra(d, dl, copy_sl);
		copy_sl = copy_sl->next;
	}
	sfd_make_all_oper_da(dl, d, lst_oper);
}

static void	next_to_sa(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;
	int			*td;

	td = ra_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 5)
	{
		td = ra_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(2, td, copy_sl->nb_rra + 1);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = rra_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra > 0)
	{
		td = rra_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(4, td, copy_sl->nb_rra - 1);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}	
}

static void	next_to_ra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;
	int			*td;

	td = ra_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 5)
	{
		td = ra_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(2, td, copy_sl->nb_rra + 1);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = sa_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 4)
	{
		td = sa_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(1, td, copy_sl->nb_rra);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
}

static void	next_to_rra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl)
{
	t_sub_lst	*nsl;
	int			*td;

	td = rra_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra > 0)
	{
		td = rra_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(4, td, copy_sl->nb_rra - 1);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = sa_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 4)
	{
		td = sa_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(1, td, copy_sl->nb_rra);
		sl_add_back(&dl_last(dl)->sub_lst, nsl);
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
}
