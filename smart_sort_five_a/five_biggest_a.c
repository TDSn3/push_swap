/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_biggest_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 08:01:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	protect_and_ini(t_data *d, t_tli **tli, t_tli **tli_cpy, int *i);
static int	check_stock_tli(t_tli *stock_tli_a, int content);

t_tli	*five_biggest_a(t_data *d, t_tli *tli, t_tli *stock_tli_a)
{
	int		i;
	int		a;
	int		b;
	t_tli	*tli_cpy;

	if (protect_and_ini(d, &tli, &tli_cpy, &i))
		return (NULL);
	while (i < d->size_a)
	{
		while (tli_cpy)
		{
			a = check_stock_tli(stock_tli_a, d->stack_a[i]);
			b = check_stock_tli(tli, d->stack_a[i]);
			if (tli_cpy->content < d->stack_a[i] && !a && !b)
			{
				find_pos_max_tli(tli)->content = d->stack_a[i];
				break ;
			}
			tli_cpy = tli_cpy->next;
		}
		tli_cpy = tli;
		i++;
	}
	return (tli);
}

static int	protect_and_ini(t_data *d, t_tli **tli, t_tli **tli_cpy, int *i)
{
	*i = 0;
	*tli_cpy = *tli;
	if (d->size_a == 0)
		return (1);
	return (0);
}

static int	check_stock_tli(t_tli *stock_tli_a, int content)
{
	if (!stock_tli_a)
		return (0);
	while (stock_tli_a)
	{
		if (stock_tli_a->content == content)
			return (1);
		stock_tli_a = stock_tli_a->next;
	}
	return (0);
}
