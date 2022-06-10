/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 13:36:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

void	rotate_choice(t_data *d, t_tli *tli)
{
	int		i;
	int		j;
	int		size_tli;
	t_tli	*best_tli;

	i = 0;
	j = 0;
	size_tli = tli_size(tli);

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
}