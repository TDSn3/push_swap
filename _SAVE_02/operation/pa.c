/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 11:35:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    pa(t_data *d)
{
	int tmp;
	int tmp_two;
	int i;

	i = 1;
	if (!d->stack_b || d->size_b < 1)
		return ;
	else
	{
		tmp = d->stack_a[0];
		d->stack_a[0] = d->stack_b[0];
		while (i < d->size_a + 1)
		{
			if (i == 1)
			{
				tmp_two = d->stack_a[i];
				d->stack_a[i] = tmp;
			}
			else
			{
				tmp = d->stack_a[i];
				d->stack_a[i] = tmp_two;
				tmp_two = tmp;
			}
			i++;
		}
		d->size_a++;
		i = 0;
		while (i < d->size_b)
		{
			if (i == d->size_b - 1)
				d->stack_b[i] = 0;
			else
				d->stack_b[i] = d->stack_b[i + 1];
			i++;
		}
		d->size_b--;
	}
}