/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 12:20:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	if_sorted_two(int *nb_oper, t_sub_lst *cpy, t_sub_lst *lst_oper);
static void	if_sorted_three(t_data *d, t_sub_lst *cpy_lo);

int	if_sorted(t_data *d, t_sub_lst *copy_sl)
{
	int			nb_oper;
	t_sub_lst	*cpy;
	t_sub_lst	*lst_oper;
	t_sub_lst	*cpy_lo;

	nb_oper = 0;
	cpy = copy_sl;
	lst_oper = sl_new(0, NULL, 0);
	if (ascending_order_tab(copy_sl->stack_after_oper, d->size_a) == -1)
	{
		if_sorted_two(&nb_oper, cpy, lst_oper);
		cpy_lo = lst_oper;
		if_sorted_three(d, cpy_lo);
		sl_int_clear(&lst_oper);
		return (nb_oper);
	}
	sl_int_clear(&lst_oper);
	return (0);
}

static void	if_sorted_two(int *nb_oper, t_sub_lst *cpy, t_sub_lst *lst_oper)
{
	while (cpy->prev_oper)
	{
		*nb_oper += 1;
		sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
		cpy = cpy->prev_oper;
	}
	*nb_oper += 1;
	sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL, 0));
}

static void	if_sorted_three(t_data *d, t_sub_lst *cpy_lo)
{
	while (cpy_lo->next)
		cpy_lo = cpy_lo->next;
	while (cpy_lo->prev)
	{
		if (cpy_lo->oper_used == 1)
			sa(d);
		if (cpy_lo->oper_used == 2)
			ra(d);
		if (cpy_lo->oper_used == 4)
			rra(d);
		cpy_lo = cpy_lo->prev;
	}
}
