/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:15:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 09:43:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    rb(t_data *d)
{
	int	stock_first;
	int i;
	
	if (!d->stack_b || d->size_b < 2)
		return ;
	stock_first = d->stack_b[0];
	i = 0;
	while (i < d->size_b)
	{
		if (i == d->size_b - 1)
			d->stack_b[i] = stock_first;
		else
			d->stack_b[i] = d->stack_b[i + 1];
		i++;
	}
	printf("rb\n");
	d->OPER_USED++;
}