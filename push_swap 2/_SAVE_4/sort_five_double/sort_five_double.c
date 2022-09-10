/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 07:11:33 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/08 19:34:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	just_one(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b);
static void	jo_two(t_data *d, t_sub_lst **cpy_lo_a);

void	sort_five_double(t_data *d)
{
	t_sub_lst	*lst_oper_a;
	t_sub_lst	*lst_oper_b;
	t_sub_lst	*cpy_lo_a;
	t_sub_lst	*cpy_lo_b;

	lst_oper_a = NULL;
	lst_oper_b = NULL;
	sfd_sort_first_five_da(d, &lst_oper_a);
	sfd_sort_first_five_b(d, &lst_oper_b);
	cpy_lo_a = lst_oper_a;
	cpy_lo_b = lst_oper_b;
	if (cpy_lo_b && cpy_lo_a)
		while_for_sfd(d, &cpy_lo_a, &cpy_lo_b);
	else
		just_one(d, &cpy_lo_a, &cpy_lo_b);
	if (lst_oper_a)
		while (lst_oper_a->prev)
			lst_oper_a = lst_oper_a->prev;
	if (lst_oper_b)
		while (lst_oper_b->prev)
			lst_oper_b = lst_oper_b->prev;
	sl_int_clear(&lst_oper_a);
	sl_int_clear(&lst_oper_b);
}

static void	just_one(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b)
{
	if (*cpy_lo_b)
	{
		while ((*cpy_lo_b)->prev)
		{
			if ((*cpy_lo_b)->oper_used == 1)
				sb(d);
			if ((*cpy_lo_b)->oper_used == 2)
				rb(d);
			if ((*cpy_lo_b)->oper_used == 4)
				rrb(d);
			*cpy_lo_b = (*cpy_lo_b)->prev;
		}		
	}
	jo_two(d, cpy_lo_a);
}

static void	jo_two(t_data *d, t_sub_lst **cpy_lo_a)
{
	if (*cpy_lo_a)
	{
		while ((*cpy_lo_a)->prev)
		{
			if ((*cpy_lo_a)->oper_used == 1)
				sa(d);
			if ((*cpy_lo_a)->oper_used == 2)
				ra(d);
			if ((*cpy_lo_a)->oper_used == 4)
				rra(d);
			*cpy_lo_a = (*cpy_lo_a)->prev;
		}					
	}	
}
