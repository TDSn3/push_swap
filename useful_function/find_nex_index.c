/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nex_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:07:13 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 18:59:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	find_index(int nb, t_index *id_lst);
static int	while_one(t_data *d, t_index *id_lst, int min_id, int max_id);
static int	while_two(t_data *d, t_index *id_lst, int min_id, int max_id);

int	find_nex_index(int min_id, int max_id, t_index *id_lst, t_data *d)
{
	int	stock_one;
	int	stock_two;
	int	stock_find_id;

	stock_one = -1;
	stock_two = -1;
	stock_find_id = find_index(d->stack_a[0], id_lst);
	if (stock_find_id >= min_id && stock_find_id < max_id)
		return (d->stack_a[0]);
	stock_one = while_one(d, id_lst, min_id, max_id);
	stock_two = while_two(d, id_lst, min_id, max_id);
	if (find_pos_a(stock_one, d) < d->size_a - find_pos_a(stock_two, d))
		return (stock_one);
	else
		return (stock_two);
}

static int	find_index(int nb, t_index *id_lst)
{
	t_index	*cpy;

	cpy = id_lst;
	while (cpy)
	{
		if (nb == cpy->content_stack)
			return (cpy->content_index);
		cpy = cpy->next;
	}
	return (-1);
}

static int	while_one(t_data *d, t_index *id_lst, int min_id, int max_id)
{
	int	i;
	int	stock_find_id;

	i = 1;
	while (i < d->size_a)
	{
		stock_find_id = find_index(d->stack_a[i], id_lst);
		if (stock_find_id >= min_id && stock_find_id < max_id)
			return (d->stack_a[i]);
		i++;
	}
	return (-1);
}

static int	while_two(t_data *d, t_index *id_lst, int min_id, int max_id)
{
	int	i;
	int	stock_find_id;

	i = d->size_a - 1;
	while (i)
	{
		stock_find_id = find_index(d->stack_a[i], id_lst);
		if (stock_find_id >= min_id && stock_find_id < max_id)
			return (d->stack_a[i]);
		i--;
	}
	return (-1);
}
