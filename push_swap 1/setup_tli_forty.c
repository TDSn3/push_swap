/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tli_forty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:25:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/27 22:16:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setup_tli_forty(t_data *d)
{
	d->tli_a_ten = NULL;
	d->tli_a_ten = tli_setup_a_forty(d, d->tli_a_ten, d->stock_tli_a_ten);
	d->tli_a_ten = five_biggest_a(d, d->tli_a_ten, d->stock_tli_a_ten);
	d->stock_tli_a_ten = tli_cpy(d->tli_a_ten, d->stock_tli_a_ten);
	up_biggest_lti_a(d, d->tli_a_ten, d->firstpart_stock_a_ten);
	d->tli_b_ten = NULL;
	d->tli_b_ten = tli_setup_b_forty(d, d->tli_b_ten, d->stock_tli_b_ten);
	d->tli_b_ten = five_smaller_b(d, d->tli_b_ten, d->stock_tli_b_ten);
	d->stock_tli_b_ten = tli_cpy(d->tli_b_ten, d->stock_tli_b_ten);
	up_smaller_tli_b(d, d->tli_b_ten, d->firstpart_stock_b_ten);
}
