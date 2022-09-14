/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:52:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 13:55:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	smart_b(t_data *d, int x)
{
	if (pos_in_stack(d->cpy_stack_b, d->size_b, x) > d->size_b / 2)
	{
		while (d->cpy_stack_b[0] != x)
		{
			rra_ot(d->cpy_stack_b, d->size_b);
			d->rrb_i++;
		}
	}
	else
	{
		while (d->cpy_stack_b[0] != x)
		{
			ra_ot(d->cpy_stack_b, d->size_b); 
			d->rb_i++;	
		}
	}
}