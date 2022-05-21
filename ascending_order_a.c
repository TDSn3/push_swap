/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_order_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:15:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 13:21:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ascending_order_a(t_data d)
{
	int	i;

	i = 0;
	if (!d.stack_a || d.size_a < 2)
		return (0);
	while (i < d.size_a - 1)
	{
		if (d.stack_a[i] > d.stack_a[i + 1])
			return (i);
		i++;
	}
	return (0);
}
