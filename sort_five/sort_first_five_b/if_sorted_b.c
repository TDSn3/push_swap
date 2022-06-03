/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:09:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	if_sorted_b(t_data *d, t_sub_lst *copy_sl)
{
	int			nb_oper;
	t_sub_lst	*cpy;
	t_sub_lst	*lst_oper;
	t_sub_lst	*cpy_lo;
	int			descending_order_size;

	if (d->size_b >= 5)
		descending_order_size = 5;
	else
		descending_order_size = d->size_b;

	nb_oper = 0;
	cpy = copy_sl;
	lst_oper = sl_new(0, NULL, 0);
	if (descending_order_tab(copy_sl->stack_after_oper, descending_order_size) == -1 && (copy_sl->nb_rra == 0 || d->size_b <= 5))
	{
		while (cpy->prev_oper)
		{
			nb_oper++;
			sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
			cpy = cpy->prev_oper;
		}
		nb_oper++;
		sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
		cpy_lo = lst_oper;
		while (cpy_lo->next)
			cpy_lo = cpy_lo->next;
		while (cpy_lo->prev)
		{
			if (cpy_lo->oper_used == 1)
				sb(d);
			if (cpy_lo->oper_used == 2)
				rb(d);
			if (cpy_lo->oper_used == 4)
				rrb(d);
			cpy_lo = cpy_lo->prev;
		}
		sl_int_clear(&lst_oper);
		return (nb_oper);
	}
	sl_int_clear(&lst_oper);
	return (0);
}
