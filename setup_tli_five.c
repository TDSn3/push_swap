/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tli_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:32:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 13:14:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setup_tli_five(t_data *d)
{
	d->tli_a_five = NULL;
	d->tli_a_five = tli_setup_a_five(d, d->tli_a_five, d->stock_tli_a_five);
	d->tli_a_five = five_biggest_a(d, d->tli_a_five, d->stock_tli_a_five);
	d->stock_tli_a_five = tli_cpy(d->tli_a_five, d->stock_tli_a_five);
	up_biggest_lti_a(d, d->tli_a_five, d->firstpart_stock_a_five);
	d->tli_b_five = NULL;
	d->tli_b_five = tli_setup_b_five(d, d->tli_b_five, d->stock_tli_b_five);
	d->tli_b_five = five_smaller_b(d, d->tli_b_five, d->stock_tli_b_five);
	d->stock_tli_b_five = tli_cpy(d->tli_b_five, d->stock_tli_b_five);
	up_smaller_tli_b(d, d->tli_b_five, d->firstpart_stock_b_five);
	sort_five_double(d);
}
