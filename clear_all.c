/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:10:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 12:26:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_all(t_data *d)
{
	tli_clear(&d->stock_tli_a_ten);
	tli_clear(&d->firstpart_stock_a_ten);
	tli_clear(&d->stock_tli_b_ten);
	tli_clear(&d->firstpart_stock_b_ten);
	tli_clear(&d->stock_tli_a_five);
	tli_clear(&d->firstpart_stock_a_five);
	tli_clear(&d->stock_tli_b_five);
	tli_clear(&d->firstpart_stock_b_five);
	free(d->stack_a);
	free(d->stack_b);
}
