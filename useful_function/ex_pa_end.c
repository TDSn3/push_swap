/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pa_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:27:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 14:32:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ex_pa_end(t_data *d, int min_id, int sz_divd)
{
	if (min_id == sz_divd * 3 && d->stock_size_a > 150)
	{	
		while (d->size_b)
		{
			pa_ot(d->cpy_stack_a, d->cpy_stack_b, d->size_a, d->size_b);
			pa(d);
		}
	}
	if (min_id == sz_divd && d->stock_size_a <= 150 && d->stock_size_a > 50)
	{	
		while (d->size_b)
		{
			pa_ot(d->cpy_stack_a, d->cpy_stack_b, d->size_a, d->size_b);
			pa(d);
		}
	}
	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
		d->rest_div += d->stock_size_a % 5;
	if (d->stock_size_a > 150)
		d->rest_div += d->stock_size_a % 10;
}
