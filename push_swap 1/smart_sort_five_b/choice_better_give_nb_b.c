/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_better_give_nb_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:32 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 07:54:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	choice_better_give_nb_b(t_data *d, int nb)
{
	int	i;
	int	top;
	int	bot;
	int	size_div;

	i = 0;
	top = 0;
	bot = d->size_b - 1;
	size_div = d->size_b / 2;
	if (d->size_b % 2 == 1 && d->size_b > 2)
		size_div++;
	while (i < size_div)
	{
		if (d->stack_b[top] == nb)
			return (i);
		if (d->stack_b[bot] == nb)
			return (i + 1);
		i++;
		top++;
		bot--;
	}
	return (0);
}
