/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_setup_a_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:09:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/10 09:19:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../header.h"

static int	check_stock_tli(t_tli *stock_tli_a, int content);

t_tli	*tli_setup_a_five(t_data *d, t_tli *tli, t_tli *stock_tli_a)
{
	int		i;
	int		j;
	int		size;

	if (d->size_a == 0)
		return (NULL);
	if (d->size_a - tli_size(stock_tli_a) > 5)
		size = 5;
	else
		size = d->size_a - tli_size(stock_tli_a);
	if (size < 1)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size && i < d->size_a)
	{
		if (!check_stock_tli(stock_tli_a, d->stack_a[i]))
		{
			tli_add_back(&tli, tli_new(d->stack_a[i]));
			j++;
		}
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