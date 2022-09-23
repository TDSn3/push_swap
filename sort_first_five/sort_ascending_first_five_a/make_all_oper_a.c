/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_oper_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/23 10:27:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	next_to_sa(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_ra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static void	next_to_rra(t_data *d, t_double_lst *dl, t_sub_lst *copy_sl);
static int	exit_error_min_one(t_data *d, t_double_lst **dl, int *td);

void	make_all_oper_a(t_double_lst *dl, t_data *d)
{
	t_sub_lst	*copy_sl;

	copy_sl = (dl_last(dl))->sub_lst;
	if (dl_add_back(&dl, dl_new()))
	{
		dl_clear(&dl);
		clear_all(d);
		exit (-1);
	}
	while (copy_sl)
	{
		if (if_sorted_a(d, copy_sl, &dl))
			return ;
		if (copy_sl->oper_used == 1)
			next_to_sa(d, dl, copy_sl);
		if (copy_sl->oper_used == 2)
			next_to_ra(d, dl, copy_sl);
		if (copy_sl->oper_used == 4)
			next_to_rra(d, dl, copy_sl);
		copy_sl = copy_sl->next;
	}
	make_all_oper_a(dl, d);
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
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = rra_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra > 0)
	{
		td = rra_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(4, td, copy_sl->nb_rra - 1);
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
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
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = sa_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 4)
	{
		td = sa_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(1, td, copy_sl->nb_rra);
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
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
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
	td = sa_dt(copy_sl->stack_after_oper, d->size_a);
	if (!check_duplicate_a(dl, d, td) && copy_sl->nb_rra < 4)
	{
		td = sa_dt(copy_sl->stack_after_oper, d->size_a);
		nsl = sl_new(1, td, copy_sl->nb_rra);
		if (sl_add_back(&dl_last(dl)->sub_lst, nsl))
			exit (exit_error_min_one(d, &dl, td));
		sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
	}
}

static int	exit_error_min_one(t_data *d, t_double_lst **dl, int *td)
{
	free(td);
	dl_clear(dl);
	clear_all(d);
	return (-1);
}
