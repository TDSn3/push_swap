/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:59:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 15:03:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	pb_sort(t_data *d, int min_index, int max_index, t_index *index_lst)
{
	int	i;
	int	stock_nb_to_find;
	int	nearest_nb;
	int	next_index;
	int	size_divided;
	int pos_max_b;

	i = 0;
	stock_nb_to_find = 0;
	nearest_nb = 0;
	next_index = 0;
	size_divided = 0;
	pos_max_b = 0;
	if (d->stock_size_a <= 50)
		size_divided = d->stock_size_a;
	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
		size_divided = d->stock_size_a / 5;
	if (d->stock_size_a > 150)
		size_divided = d->stock_size_a / 10;
	if (min_index < size_divided)
	{
		size_divided += min_index;
		min_index = 0;
	}
	while (i < size_divided)
	{				
		next_index = find_nex_index(min_index, max_index, index_lst, d);
		if (d->stack_a[0] != next_index)
			smart_a(d, next_index);
		stock_nb_to_find = find_nb(i, index_lst);
		nearest_nb = smart_insertion(d, d->cpy_stack_a[0]);
		if (nearest_nb != d->cpy_stack_a[0])
		{
			while (d->cpy_stack_b[0] != nearest_nb)
				smart_b(d, nearest_nb);
		}
		else
		{
			pos_max_b = find_pos_max_b(d);
			while (d->cpy_stack_b[0] != pos_max_b)
				smart_b(d, pos_max_b);
		}
		exe_rr_rrr(d);		
		pa_ot(d->cpy_stack_b, d->cpy_stack_a, d->size_b, d->size_a);
		pb(d);

		i++;
	}
	up_biggest_b(d);
	ex_pa_end(d, min_index, size_divided);
	if (min_index >= size_divided)
		pb_sort(d, min_index - size_divided, max_index - size_divided, index_lst);
}
