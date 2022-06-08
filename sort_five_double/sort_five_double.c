/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 07:11:33 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/08 09:40:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_five_double(t_data *d)
{
	t_sub_lst	*lst_oper_a;
	t_sub_lst	*lst_oper_b;
	t_sub_lst	*cpy_lo_a;
	t_sub_lst	*cpy_lo_b;

	lst_oper_a = NULL;
	lst_oper_b = NULL;
	sfd_sort_first_five_a(d, &lst_oper_a);
	sfd_sort_first_five_b(d, &lst_oper_b);
	cpy_lo_a = lst_oper_a;
	cpy_lo_b = lst_oper_b;
	while (cpy_lo_a->prev || cpy_lo_b->prev)
	{
		if (cpy_lo_a->oper_used == 1 && cpy_lo_b->oper_used == 1)
			ss(&d);
		else
		{
			if (cpy_lo_a->oper_used == 1)
				sa(d);	
			if (cpy_lo_b->oper_used == 1)
				sb(d);		
		}
		
		if (cpy_lo_a->oper_used == 2 && cpy_lo_b->oper_used == 2)
			rr(&d);
		else
		{
			if (cpy_lo_a->oper_used == 2)
				ra(d);	
			if (cpy_lo_b->oper_used == 2)
				rb(d);		
		}
		
		if (cpy_lo_a->oper_used == 4 && cpy_lo_b->oper_used == 4)
			rrr(&d);
		else
		{
			if (cpy_lo_a->oper_used == 4)
				rra(d);	
			if (cpy_lo_b->oper_used == 4)
				rrb(d);		
		}
		if(cpy_lo_a->prev)
			cpy_lo_a = cpy_lo_a->prev;
		if(cpy_lo_b->prev)
			cpy_lo_b = cpy_lo_b->prev;
	}
	while (lst_oper_a->prev)
		lst_oper_a = lst_oper_a->prev;
	while (lst_oper_b->prev)
		lst_oper_b = lst_oper_b->prev;
	sl_int_clear(&lst_oper_a);
	sl_int_clear(&lst_oper_b);
}