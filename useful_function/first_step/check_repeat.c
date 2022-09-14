/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:47:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/05 16:03:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_repeat(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->size_a)
	{
		j = i + 1;
		while (j < d->size_a)
		{
			if (d->stack_a[i] == d->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
