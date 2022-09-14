/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:45:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 13:49:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	smart_a(t_data *d, int next_index)
{
	if (pos_in_stack(d->stack_a, d->size_a, next_index) > d->size_a / 2)
	{
		while (d->cpy_stack_a[0] != next_index)
		{
			rra_ot(d->cpy_stack_a, d->size_a);
			d->rra_i++;
		}
	}
	else
	{
		while (d->cpy_stack_a[0] != next_index)
		{
			ra_ot(d->cpy_stack_a, d->size_a);
			d->ra_i++;
		}
	}
}