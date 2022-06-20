/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_better_give_nb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:32 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 12:51:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

int	choice_better_give_nb(t_data *d, int nb)
{
	int	i;
	int top;
	int	bot;
	int	size_div;

	i = 0;
	top = 0;
	bot = d->size_a - 1;
	size_div = d->size_a / 2;
	
	if (d->size_a % 2 == 1 && d->size_a > 2)
		size_div++;

	while (i < size_div)
	{
		if (d->stack_a[top] == nb)
			return (i);
		if (d->stack_a[bot] == nb)
			return (i + 1);
		i++;
		top++;
		bot--;
	}
	return (0);
}