/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_setup_b_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:09:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:44:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	check_stock_tli(t_tli *stock_tli_b, int content);

t_tli	*tli_setup_b_ten(t_data *d, t_tli *tli, t_tli *stock_tli_b)
{
	int		i;
	int		j;
	int		size;

	if (d->size_b == 0)
		return (NULL);
	if (d->size_b - tli_size(stock_tli_b) > 40)
		size = 40;
	else
		size = d->size_b - tli_size(stock_tli_b);
	if (size < 1)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size && i < d->size_b)
	{
		if (!check_stock_tli(stock_tli_b, d->stack_b[i]))
		{
			tli_add_back(&tli, tli_new(d->stack_b[i]));
			j++;
		}
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
