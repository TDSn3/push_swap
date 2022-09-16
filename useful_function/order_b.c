/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:16:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 18:17:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	order_b(int nb, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->size_b && d->size_b > 2)
	{
		if (nb < d->stack_b[i])
		{
			while (nb < d->stack_b[i])
			{
				i++;
			}
			return (i);
		}
		i++;
	}
	return (0);
}
