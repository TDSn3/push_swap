/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_max_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:12:32 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 14:13:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	find_pos_max_b(t_data *d)
{
	int i;
	int	stock_max;

	i = 1;
	stock_max = d->cpy_stack_b[0];
	while (i < d->size_b)
	{
		if (d->cpy_stack_b[i] > stock_max)
			stock_max = d->cpy_stack_b[i];
		i++;
	}
	return (stock_max);
}
