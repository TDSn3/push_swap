/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_order_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:15:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/21 13:21:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ascending_order_b(t_data d)
{
	int	i;

	i = 0;
	if (!d.stack_b || d.size_b < 2)
		return (0);
	while (i < d.size_b - 1)
	{
		if (d.stack_b[i] > d.stack_b[i + 1])
			return (i);
		i++;
	}
	return (0);
}
