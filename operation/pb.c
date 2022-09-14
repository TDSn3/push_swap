/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:53:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 08:25:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	pb_two(t_data *d, int i);

void	pb(t_data *d)
{
	int	tmp;
	int	tmp_two;
	int	i;

	i = 1;
	if (!d->stack_a || d->size_a < 1)
		return ;
	tmp = d->stack_b[0];
	d->stack_b[0] = d->stack_a[0];
	while (i < d->size_b + 1)
	{
		if (i == 1)
		{
			tmp_two = d->stack_b[i];
			d->stack_b[i] = tmp;
		}
		else
		{
			tmp = d->stack_b[i];
			d->stack_b[i] = tmp_two;
			tmp_two = tmp;
		}
		i++;
	}
	pb_two(d, i);
}

static void	pb_two(t_data *d, int i)
{
	d->size_b++;
	i = 0;
	while (i < d->size_a)
	{
		if (i == d->size_a - 1)
			d->stack_a[i] = 0;
		else
			d->stack_a[i] = d->stack_a[i + 1];
		i++;
	}
	d->size_a--;
	write(1, "pb\n", 3);
}
