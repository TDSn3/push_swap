/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    pa(t_data d)
{
	int tmp;
	int tmp_two;
	int i;

	i = 1;
	if (!d.stack_b || d.size_b < 1)
		return ;
	else
	{
		tmp = d.stack_a[0];
		d.stack_a[0] = d.stack_b[0];
		while (i < d.size_a)
		{
			if (i == 1)
			{
				tmp_two = d.stack_a[i];
				d.stack_a[i] = tmp;
			}
			else
			{
				tmp = d.stack_a[i];
				d.stack_a[i] = tmp_two;
				tmp_two = tmp;
			}
			i++;
		}
		i = 0;
		tmp = d.stack_b[0];
		while (i < d.size_b)
		{
			if (i == 0)
			{
				tmp_two = d.stack_b[i];
				d.stack_a[i] = tmp;
			}
			else
			{
				tmp = d.stack_a[i];
				d.stack_a[i] = tmp_two;
				tmp_two = tmp;
			}
			i++;
		}

	}
}