/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_smaller_tli_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:35:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/10 14:04:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

void    up_smaller_tli_b(t_data *d, t_tli *tli, t_tli *firstpart_stock)
{
	int		i;
	int		j;
	int		size_tli;
	int		size_tli_save;
	t_tli	*best_tli;

	i = 0;
	j = 0;
	size_tli = tli_size(tli);
	size_tli_save = tli_size(tli);

	while (size_tli && tli)
	{
		best_tli = choice_better_b(d, tli);
		while (i < d->size_b && d->stack_b[i] != best_tli->content)
			i++;
		if (pos_in_stack(d->stack_b, d->size_b, d->stack_b[i]) > d->size_b / 2)
		{
			while (d->stack_b[0] != best_tli->content && j < d->size_b)
			{
				rrb(d);
				j++;
			}
			j = 0;
			pa(d);
		}
		else
		{
			while (d->stack_b[0] != best_tli->content && j < d->size_b)
			{
				rb(d);
				j++;
			}
			j = 0;
			pa(d);
		}
		i = 0;
		tli_clear_one(&tli, best_tli->content);
		size_tli--;
	}

	i = 0;
	j = 0;

	if (firstpart_stock)
	{
		while (i < d->size_b && d->stack_b[i] != find_pos_min_tli(firstpart_stock)->content)
			i++;
		if (d->stack_b[0] != find_pos_min_tli(firstpart_stock)->content)
		{
			if (pos_in_stack(d->stack_b, d->size_b, d->stack_b[i]) > d->size_b / 2)
			{
				while (d->stack_b[0] != find_pos_min_tli(firstpart_stock)->content && j < d->size_b)
				{
					rrb(d);
					j++;
				}
				j = 0;
			}
			else
			{
				while (d->stack_b[0] != find_pos_min_tli(firstpart_stock)->content && j < d->size_b)
				{
					rb(d);
					j++;
				}
				j = 0;
			}
		}
	}
	while (size_tli_save)
	{
		pb(d);
		size_tli_save--;
	}
}