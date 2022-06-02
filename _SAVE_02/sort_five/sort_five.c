/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 20:55:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    sort_five(t_data d)
{
	t_double_lst	*dl;

	dl = dl_new();
    
	if (ascending_order_tab(d.stack_a, d.size_a) == -1)
		return;
	dl->sub_lst = sl_new(1, sa_dt(d.stack_a, d.size_a));
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
		return;
	sl_add_back(&dl->sub_lst, sl_new(2, ra_dt(d.stack_a, d.size_a)));
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
		return;
	sl_add_back(&dl->sub_lst, sl_new(4, rra_dt(d.stack_a, d.size_a)));
	if (if_sorted(&d, (dl_last(dl))->sub_lst))
		return;

	printf("\n");
	make_all_oper(dl, &d, 1);  
    dl_clear(&dl);
}
