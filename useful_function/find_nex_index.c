/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nex_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:07:13 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 14:10:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	find_index(int nb, t_index *id_lst);

int	find_nex_index(int min_id, int max_id, t_index *id_lst, t_data *d)
{
	int	i;
	int	stock_one;
	int	stock_two;

	stock_one = -1;
	stock_two = -1;
	if (find_index(d->stack_a[0], id_lst) >= min_id && find_index(d->stack_a[0], id_lst) < max_id)
		return (d->stack_a[0]);
	i = 1;
	while (i < d->size_a)
	{
		if (find_index(d->stack_a[i], id_lst) >= min_id && find_index(d->stack_a[i], id_lst) < max_id)
		{
			stock_one = d->stack_a[i];
			break ;
		}
		i++;
	}
	i = d->size_a - 1;
	while (i)
	{
		if (find_index(d->stack_a[i], id_lst) >= min_id && find_index(d->stack_a[i], id_lst) < max_id)
		{
			stock_two = d->stack_a[i];
			break ;
		}
		i--;
	}
	if (find_pos_a(stock_one, d) < d->size_a - find_pos_a(stock_two, d))
		return (stock_one);
	else
		return (stock_two);
}

static int	find_index(int nb, t_index *id_lst)
{
	t_index *cpy;

	cpy = id_lst;

	while (cpy)
	{
		if (nb == cpy->content_stack)
			return (cpy->content_index);	
		cpy = cpy->next;	
	}
	return (-1);
}