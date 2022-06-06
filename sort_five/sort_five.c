/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:06:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    sort_five(t_data d)
{
	t_double_lst	*dl;

	dl = dl_new();
	if (ascending_order_tab(d.stack_a, d.size_a) == -1)
	{
		dl_clear(&dl);
		return;
	}
	dl->sub_lst = sl_new(1, sa_dt(d.stack_a, d.size_a), 0);
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
	{
		dl_clear(&dl);
		return;
	}
	sl_add_back(&dl->sub_lst, sl_new(2, ra_dt(d.stack_a, d.size_a), 0));
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
	{
		dl_clear(&dl);
		return;
	}
	sl_add_back(&dl->sub_lst, sl_new(4, rra_dt(d.stack_a, d.size_a), 0));
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
	{
		dl_clear(&dl);
		return;
	}
	make_all_oper(dl, &d, 0);
	dl_clear(&dl);
}
