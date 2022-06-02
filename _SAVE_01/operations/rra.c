/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    rra(t_data *d)
{
    int tmp;
	int tmp_two;
	int i;
	
	if (!d->stack_a || d->size_a < 2)
		return ;
	i = 0;
	while (i < d->size_a)
	{
		if (i == 0)
		{
			tmp_two = d->stack_a[i];
			d->stack_a[i] = d->stack_a[d->size_a - 1];
		}
        else
        {
            tmp = d->stack_a[i];
            d->stack_a[i] = tmp_two;
            tmp_two = tmp;
        }
		i++;
	}
}