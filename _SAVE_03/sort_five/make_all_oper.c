/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:13:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	check_duplicate(t_double_lst *dl, t_data *d, int *tab);

void   make_all_oper(t_double_lst *dl, t_data *d, int i)
{
	t_sub_lst	*copy_sl;

	copy_sl = (dl_last(dl))->sub_lst;
	dl_add_back(&dl, dl_new());
	while (copy_sl)
	{
		if (if_sorted(d, copy_sl))
			return;
		if (copy_sl->oper_used == 1) // SA
		{
			if (!check_duplicate(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a), 0));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a), 0));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 2) // RA
		{
			if (!check_duplicate(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a), 0));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a), 0));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 4) // RRA
		{
			if (!check_duplicate(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a), 0));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_a)))
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a), 0));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		copy_sl = copy_sl->next;
	}
	i++;
	make_all_oper(dl, d, i);
}

static int	check_duplicate(t_double_lst *dl, t_data *d, int *tab)
{
	t_double_lst	*copydl;
	t_sub_lst		*copysl;
	int				i;
	int				j;
	
	i = 0;
	j = 0;
	copydl = dl;
	if (!tab)
		return (0);
	while (copydl)
	{
		if (!dl || !dl->sub_lst || !dl->sub_lst->stack_after_oper)
		{
			free(tab);
			return (0);
		}
		copysl = copydl->sub_lst;
		while (copysl)
		{
			while (i < d->size_a)
			{
				if (copysl->stack_after_oper[i] == tab[i])
					j++;
				i++;
			}
			if (j == d->size_a)
			{
				free(tab);
				return (1);
			}
			i = 0;
			j = 0;
			copysl = copysl->next;
		}
		copydl = copydl->next;
	}
	free(tab);
	return (0);
}
