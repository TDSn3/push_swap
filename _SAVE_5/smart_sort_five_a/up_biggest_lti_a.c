/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_biggest_lti_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:35:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/08 20:18:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

void    up_biggest_lti_a(t_data *d, t_tli *tli, t_tli *firstpart_stock)
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
		best_tli = choice_better(d, tli);
		while (i < d->size_a && d->stack_a[i] != best_tli->content)
			i++;
		if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
		{
			while (d->stack_a[0] != best_tli->content && j < d->size_a)
			{
				rra(d);
				j++;
			}
			j = 0;
			pb(d);
		}
		else
		{
			while (d->stack_a[0] != best_tli->content && j < d->size_a)
			{
				ra(d);
				j++;
			}
			j = 0;
			pb(d);
		}
		i = 0;
		tli_clear_one(&tli, best_tli->content);
		size_tli--;
	}
	if (firstpart_stock)
		while (d->stack_a[0] != find_pos_max_tli(firstpart_stock)->content)
			ra(d);
	while (size_tli_save)
	{
		pa(d);
		size_tli_save--;
	}
}