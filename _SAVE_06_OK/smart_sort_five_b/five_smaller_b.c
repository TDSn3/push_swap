/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_smaller_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:18:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/10 12:20:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header.h"

static int	check_stock_tli(t_tli *stock_tli_b, int content);

t_tli	*five_smaller_b(t_data *d, t_tli *tli, t_tli *stock_tli_b)
{
	int	i;
	t_tli	*tli_cpy;
	
	i = 0;
	tli_cpy = tli;
	if (d->size_b == 0)
		return (NULL);

	while (i < d->size_b)
	{
		while (tli_cpy)
		{
			if (tli_cpy->content > d->stack_b[i] && !check_stock_tli(stock_tli_b, d->stack_b[i]) && !check_stock_tli(tli, d->stack_b[i]))
			{
				find_pos_min_tli(tli)->content = d->stack_b[i];
				break;
			}
			tli_cpy = tli_cpy->next;
		}
		tli_cpy = tli;
		i++;
	}
	return (tli);
}

static int	check_stock_tli(t_tli *stock_tli_b, int content)
{
	if (!stock_tli_b)
		return (0);
	while (stock_tli_b)
	{
		if (stock_tli_b->content == content)
			return (1);
		stock_tli_b = stock_tli_b->next;
	}
	return (0);
}