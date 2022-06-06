/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_five_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:08:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    sort_first_five_b(t_data d)
{
	t_double_lst	*dl;
	int				descending_order_size;

	if (d.size_b >= 5)
		descending_order_size = 5;
	else
		descending_order_size = d.size_b;

	dl = dl_new();
	if (descending_order_tab(d.stack_b, descending_order_size) == -1)
	{
		dl_clear(&dl);
		return;	
	}
	dl->sub_lst = sl_new(1, sa_dt(d.stack_b, d.size_b), 0);
	if (if_sorted_b(&d, (dl_last(dl))->sub_lst))
	{
		dl_clear(&dl);
		return;	
	}
	sl_add_back(&dl->sub_lst, sl_new(2, ra_dt(d.stack_b, d.size_b), 1));
	if (d.size_b <= 5)
	{
		if (if_sorted_b(&d, (dl_last(dl))->sub_lst))
		{
			dl_clear(&dl);
			return;	
		}
		sl_add_back(&dl->sub_lst, sl_new(4, rra_dt(d.stack_b, d.size_b), 0));
		if (if_sorted_b(&d, (dl_last(dl))->sub_lst))
		{
			dl_clear(&dl);
			return;	
		}
	}
	make_all_oper_b(dl, &d);  
    dl_clear(&dl);
}
