/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_biggest_lti_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:35:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 10:55:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	part_two(t_data *d, t_tli *best_tli, int i);
static void	b_p(t_data *d, t_tli *firstpart_stock, int sts);
static void	p_iii(t_data *d, t_tli *firstpart_stock, int i);

void	up_biggest_lti_a(t_data *d, t_tli *tli, t_tli *firstpart_stock)
{
	int		i;
	int		size_tli;
	int		size_tli_save;
	t_tli	*best_tli;

	i = 0;
	size_tli = tli_size(tli);
	size_tli_save = tli_size(tli);
	while (size_tli && tli)
	{
		best_tli = choice_better(d, tli);
		while (i < d->size_a && d->stack_a[i] != best_tli->content)
			i++;
		part_two(d, best_tli, i);
		i = 0;
		tli_clear_one(&tli, best_tli->content);
		size_tli--;
	}
	b_p(d, firstpart_stock, size_tli_save);
}

static void	part_two(t_data *d, t_tli *best_tli, int i)
{
	int	j;

	j = 0;
	if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
	{
		while (d->stack_a[0] != best_tli->content && j < d->size_a)
		{
			rra(d);
			j++;
		}
		pb(d);
	}
	else
	{
		while (d->stack_a[0] != best_tli->content && j < d->size_a)
		{
			ra(d);
			j++;
		}
		pb(d);
	}	
}

static void	b_p(t_data *d, t_tli *firstpart_stock, int sts)
{
	int	i;
	int	a;

	i = 0;
	if (firstpart_stock)
	{
		a = find_pos_max_tli(firstpart_stock)->content;
		while (i < d->size_a && d->stack_a[i] != a)
			i++;
		p_iii(d, firstpart_stock, i);
	}
	while (sts)
	{
		pa(d);
		sts--;
	}
}

static void	p_iii(t_data *d, t_tli *firstpart_stock, int i)
{
	int	j;
	int	a;

	j = 0;
	if (d->stack_a[0] != find_pos_max_tli(firstpart_stock)->content)
	{
		if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
		{
			a = find_pos_max_tli(firstpart_stock)->content;
			while (d->stack_a[0] != a && j < d->size_a)
			{
				rra(d);
				j++;
			}
		}
		else
		{
			a = find_pos_max_tli(firstpart_stock)->content;
			while (d->stack_a[0] != a && j < d->size_a)
			{
				ra(d);
				j++;
			}
		}
	}
}
