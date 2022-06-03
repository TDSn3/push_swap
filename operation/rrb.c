/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:11:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 17:18:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    rrb(t_data *d)
{
    int tmp;
	int tmp_two;
	int i;
	
	if (!d->stack_b || d->size_b < 2)
		return ;
	i = 0;
	while (i < d->size_b)
	{
		if (i == 0)
		{
			tmp_two = d->stack_b[i];
			d->stack_b[i] = d->stack_b[d->size_b - 1];
		}
        else
        {
            tmp = d->stack_b[i];
            d->stack_b[i] = tmp_two;
            tmp_two = tmp;
        }
		i++;
	}
	printf("rrb\n");
}