/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_biggest_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:34:16 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:46:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	up_biggest_b(t_data *d)
{
	int	pos_max_b;

	pos_max_b = find_pos_max_b(d);
	while (d->stack_b[0] != pos_max_b)
	{
		if (pos_in_stack(d->stack_b, d->size_b, pos_max_b) > d->size_b / 2)
		{
			while (d->stack_b[0] != pos_max_b)
			{
				rra_ot(d->cpy_stack_b, d->size_b);
				rrb(d);
			}
		}
		else
		{
			while (d->stack_b[0] != pos_max_b)
			{
				ra_ot(d->cpy_stack_b, d->size_b);
				rb(d);
			}
		}			
	}
}
