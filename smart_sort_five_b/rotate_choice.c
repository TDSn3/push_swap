/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 10:35:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	part_two(t_data *d, t_tli *best_tli);
static void	part_three(t_data *d, t_tli *best_tli);

void	rotate_choice(t_data *d, t_tli *tli)
{
	int		i;
	int		size_tli;
	t_tli	*best_tli;

	i = 0;
	size_tli = tli_size(tli);
	while (size_tli && tli)
	{
		best_tli = choice_better(d, tli);
		while (i < d->size_a && d->stack_a[i] != best_tli->content)
			i++;
		if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
			part_two(d, best_tli);
		else
			part_three(d, best_tli);
		i = 0;
		tli_clear_one(&tli, best_tli->content);
		size_tli--;
	}
}

static void	part_two(t_data *d, t_tli *best_tli)
{
	int	j;

	j = 0;
	while (d->stack_a[0] != best_tli->content && j < d->size_a)
	{
		rra(d);
		j++;
	}
	pb(d);
}

static void	part_three(t_data *d, t_tli *best_tli)
{
	int	j;

	j = 0;
	while (d->stack_a[0] != best_tli->content && j < d->size_a)
	{
		ra(d);
		j++;
	}
	pb(d);
}
