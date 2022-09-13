/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_for_sfd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:57:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/09 14:16:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	part_two(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b);

void	while_for_sfd_r(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b)
{
	while ((*cpy_lo_a)->prev || (*cpy_lo_b)->prev)
	{	
		if ((*cpy_lo_a)->oper_used == 1 && (*cpy_lo_b)->oper_used == 1)
			ss(&d);
		else
		{
			if ((*cpy_lo_a)->oper_used == 1)
				sa(d);
			if ((*cpy_lo_b)->oper_used == 1)
				sb(d);
		}
		if ((*cpy_lo_a)->oper_used == 2 && (*cpy_lo_b)->oper_used == 2)
			rr(&d);
		else
		{
			if ((*cpy_lo_a)->oper_used == 2)
				ra(d);
			if ((*cpy_lo_b)->oper_used == 2)
				rb(d);
		}
		part_two(d, cpy_lo_a, cpy_lo_b);
	}
}

static void	part_two(t_data *d, t_sub_lst **cpy_lo_a, t_sub_lst **cpy_lo_b)
{
	if ((*cpy_lo_a)->oper_used == 4 && (*cpy_lo_b)->oper_used == 4)
		rrr(&d);
	else
	{
		if ((*cpy_lo_a)->oper_used == 4)
			rra(d);
		if ((*cpy_lo_b)->oper_used == 4)
			rrb(d);
	}
	if ((*cpy_lo_a)->prev)
		*cpy_lo_a = (*cpy_lo_a)->prev;
	if ((*cpy_lo_b)->prev)
		*cpy_lo_b = (*cpy_lo_b)->prev;
}
