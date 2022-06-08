/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_biggest_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/08 13:11:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

static int	check_stock_tli(t_tli *stock_tli_a, int content);

t_tli	*five_biggest_a(t_data *d, t_tli *tli, t_tli *stock_tli_a)
{
	int	i;
	t_tli	*tli_cpy;
	
	i = 0;
	tli_cpy = tli;
	if (d->size_a == 0)
		return (NULL);

	while (i < d->size_a)
	{
		while (tli_cpy)
		{
			if (tli_cpy->content < d->stack_a[i] && !check_stock_tli(stock_tli_a, d->stack_a[i]) && !check_stock_tli(tli, d->stack_a[i]))
			{
				find_pos_max_tli(tli)->content = d->stack_a[i];
				break;
			}
			tli_cpy = tli_cpy->next;
		}
		tli_cpy = tli;
		i++;
	}
	return (tli);
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