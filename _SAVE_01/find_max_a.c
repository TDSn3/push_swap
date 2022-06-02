/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:34:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 15:34:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int find_max_a(t_data d)
{
	int	i;
	int stock_max;
	int stock_pos_max;

	i = 0;
	if (!d.stack_a || d.size_a < 1)
		return (-1);
	stock_max = d.stack_a[0];
	stock_pos_max = 0;
	while (i < d.size_a)
	{
		if (stock_max < d.stack_a[i])
		{
			stock_max = d.stack_a[i];
			stock_pos_max = i;
		}
		i++;
	}
	return (stock_pos_max);
}
