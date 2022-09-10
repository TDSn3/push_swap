/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfd_if_sorted_b_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/09 14:47:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	part_two(t_sub_lst *cpy, t_sub_lst **lst_oper);

int	sfd_if_sorted_b_r(t_data *d, t_sub_lst *copy_sl, t_sub_lst **lst_oper)
{
	t_sub_lst	*cpy;
	t_sub_lst	*cpy_lo;
	int			descending_order_size;
	int			dt;

	if (d->size_b >= 5)
		descending_order_size = 5;
	else
		descending_order_size = d->size_b;
	cpy = copy_sl;
	*lst_oper = sl_new(0, NULL, 0);
	dt = descending_order_tab(copy_sl->stack_after_oper, descending_order_size);
	if (dt == -1 && (copy_sl->nb_rra == 0 || d->size_b <= 5))
	{
		part_two(cpy, lst_oper);
		cpy_lo = *lst_oper;
		while (cpy_lo->next)
			cpy_lo = cpy_lo->next;
		*lst_oper = cpy_lo;
		return (1);
	}
	sl_int_clear(lst_oper);
	return (0);
}

static void	part_two(t_sub_lst *cpy, t_sub_lst **lst_oper)
{
	while (cpy->prev_oper)
	{
		sl_add_back(lst_oper, sl_new(cpy->oper_used, NULL, 0));
		cpy = cpy->prev_oper;
	}
	sl_add_back(lst_oper, sl_new(cpy->oper_used, NULL, 0));
}
