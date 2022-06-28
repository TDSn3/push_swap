/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_while_run_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:50:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/28 19:52:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	next_while_run_two(t_data *d, int nb_while)
{
	t_tli	*a;

	if (d->stock_size_stack > 150)
	{
		if (nb_while % 8 == 0)
			setup_tli_forty(d);
		setup_tli_five(d);
		if (nb_while % 8 == 0)
		{
			a = tli_cpy(d->stock_tli_a_ten, d->firstpart_stock_a_ten);
			d->firstpart_stock_a_ten = a;
			a = tli_cpy(d->stock_tli_b_ten, d->firstpart_stock_b_ten);
			d->firstpart_stock_b_ten = a;
		}
	}
}