/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 16:10:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void   make_all_oper(t_double_lst *dl, t_data *d, int i)
{
	t_sub_lst	*copy_sl = (dl_last(dl))->sub_lst;
	dl_add_back(&dl, dl_new());

	printf("\n\033[33;1;2m%d:\033[00m", i);
	while (copy_sl)
	{
		if (ascending_order_tab(copy_sl->stack_after_oper, d->size_a) == -1)
		{
			d->find = copy_sl;
			printf(" \033[33;01m[SORTED]\033[00m\n\n");

			t_sub_lst   *cpy = copy_sl;
			printf("\n\n");
			while (cpy->prev_oper)
			{
				for(int i = 0; i < d->size_a; i++)
					printf("%d\n", cpy->stack_after_oper[i]);
				printf("\n(+%d)\n\n", cpy->oper_used);
				cpy = cpy->prev_oper;
			}
			for(int i = 0; i < d->size_a; i++)
				printf("%d\n", cpy->stack_after_oper[i]);
			printf("\n(+%d)\n\n", cpy->oper_used);
			for(int i = 0; i < d->size_a; i++)
				printf("%d\n", d->stack_a[i]);
			return ;
		}

		if (copy_sl->oper_used == 1) // SA
		{
			printf(" 1)");
			printf("+2");
			sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a)));
			sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			if (ascending_order_tab(sl_last(dl_last(dl)->sub_lst)->stack_after_oper, d->size_a) > -1)
			{
				printf("+4");
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a)));
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 2) // RA
		{
			printf(" 2)");
			printf("+2");
			sl_add_back(&dl_last(dl)->sub_lst, sl_new(2, ra_dt(copy_sl->stack_after_oper, d->size_a)));
			sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			if (ascending_order_tab(sl_last(dl_last(dl)->sub_lst)->stack_after_oper, d->size_a) > -1)
			{
				printf("+1");
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a)));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		if (copy_sl->oper_used == 4) // RRA
		{
			printf(" 4)");
			printf("+4");
			sl_add_back(&dl_last(dl)->sub_lst, sl_new(4, rra_dt(copy_sl->stack_after_oper, d->size_a)));
			sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			if (ascending_order_tab(sl_last(dl_last(dl)->sub_lst)->stack_after_oper, d->size_a) > -1)
			{
				printf("+1");
				sl_add_back(&dl_last(dl)->sub_lst, sl_new(1, sa_dt(copy_sl->stack_after_oper, d->size_a)));	
				sl_link(sl_last(dl_last(dl)->sub_lst), copy_sl);
			}
		}
		copy_sl = copy_sl->next;
	}
	i++;
	make_all_oper(dl, d, i);
}