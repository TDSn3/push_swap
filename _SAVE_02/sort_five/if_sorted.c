/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:19:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/02 00:05:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	if_sorted(t_data *d, t_sub_lst *copy_sl)
{
	int			nb_oper;
	t_sub_lst	*cpy;
	t_sub_lst	*lst_oper;
	t_sub_lst	*cpy_lo;

	nb_oper = 0;
	cpy = copy_sl;
	lst_oper = sl_new(0, NULL);
	if (ascending_order_tab(copy_sl->stack_after_oper, d->size_a) == -1)
	{
		printf(" \033[33;01m[SORTED]\033[00m\n\n");
		while (cpy->prev_oper)
		{
			nb_oper++;
			printf("(+%d) ", cpy->oper_used);
			sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL));
			cpy = cpy->prev_oper;
		}
		nb_oper++;
		sl_add_back(&lst_oper, sl_new(cpy->oper_used, NULL));
		printf("(+%d) %d operation\n", cpy->oper_used, nb_oper);

		printf("\n\n");
		cpy_lo = lst_oper;
		while (cpy_lo->next)
			cpy_lo = cpy_lo->next;
		while (cpy_lo->prev)
		{
			printf("%d ", cpy_lo->oper_used);
			if (cpy_lo->oper_used == 1)
				sa(d);
			if (cpy_lo->oper_used == 2)
				ra(d);
			if (cpy_lo->oper_used == 4)
				rra(d);
			cpy_lo = cpy_lo->prev;
		}
		printf("\n\n");

		sl_int_clear(&lst_oper);
		return (nb_oper);
	}
	sl_int_clear(&lst_oper);
	return (0);
}
/*
static void	show_tab(t_data *d, int *tab)
{
	int	i;

	i = 0;
	while (i < d->size_a)
	{
		printf("%d\n", tab[i++]);
	}
}
*/