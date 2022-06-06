/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_five_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 15:16:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    sort_first_five_a(t_data d)
{
	t_double_lst	*dl;
	int				ascending_order_size;

	if (d.size_a >= 5)
		ascending_order_size = 5;
	else
		ascending_order_size = d.size_a;

	dl = dl_new();
	if (ascending_order_tab(d.stack_a, ascending_order_size) == -1)
		return;
	dl->sub_lst = sl_new(1, sa_dt(d.stack_a, d.size_a), 0);
	if (if_sorted_a(&d, (dl_last(dl))->sub_lst))
		return;
	sl_add_back(&dl->sub_lst, sl_new(2, ra_dt(d.stack_a, d.size_a), 1));
	if (d.size_a <= 5)
	{
		if (if_sorted_a(&d, (dl_last(dl))->sub_lst))
			return;
		sl_add_back(&dl->sub_lst, sl_new(4, rra_dt(d.stack_a, d.size_a), 0));
		if (if_sorted_a(&d, (dl_last(dl))->sub_lst))
			return;
	}
	make_all_oper_a(dl, &d);  
    dl_clear(&dl);
}
