/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfd_make_all_oper_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 13:40:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	check_duplicate(t_double_lst *dl, t_data *d, int *tab);

void   sfd_make_all_oper_b(t_double_lst *dl, t_data *d, t_sub_lst **lst_oper)
{
	t_sub_lst	*copy_sl;

	copy_sl = (dl_last(dl))->sub_lst;	
	dl_add_back(&dl, dl_new());
	while (copy_sl)
	{	
		if (sfd_if_sorted_b(d, copy_sl, lst_oper))
			return;
		if (copy_sl->oper_used == 1) // SA
		{
			if (!check_duplicate(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra < 5)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra + 1));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra > 0)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra - 1));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 2) // RA
		{
			if (!check_duplicate(dl, d, ra_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra < 5)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra + 1));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra < 4)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 4) // RRA
		{
			if (!check_duplicate(dl, d, rra_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra > 0)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra - 1));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
			if (!check_duplicate(dl, d, sa_dt(copy_sl->stack_after_oper, d->size_b)) && copy_sl->nb_rra < 4)
			{
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_b), copy_sl->nb_rra));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		copy_sl = copy_sl->next;
	}
	sfd_make_all_oper_b(dl, d, lst_oper);
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
			while (i < d->size_b)
			{
				if (copysl->stack_after_oper[i] == tab[i])
					j++;
				i++;
			}
			if (j == d->size_b)
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
