/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:03:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:56:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	smart_insertion(t_data *d, int nb)
{
	int	stock_min;
	int	i;

	i = 0;
	stock_min = nb;
	while (i < d->size_b)
	{
		if (stock_min == nb)
		{
			if (d->cpy_stack_b[i] < nb)
				stock_min = d->cpy_stack_b[i];
		}
		else if (stock_min != nb)
		{
			if (d->cpy_stack_b[i] > stock_min && d->cpy_stack_b[i] < nb)
				stock_min = d->cpy_stack_b[i];
		}
		i++;
	}
	return (stock_min);
}
