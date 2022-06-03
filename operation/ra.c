/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:18:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    ra(t_data *d)
{
	int	stock_first;
	int i;
	
	if (!d->stack_a || d->size_a < 2)
		return ;
	stock_first = d->stack_a[0];
	i = 0;
	while (i < d->size_a)
	{
		if (i == d->size_a - 1)
			d->stack_a[i] = stock_first;
		else
			d->stack_a[i] = d->stack_a[i + 1];
		i++;
	}
	printf("ra\n");
}