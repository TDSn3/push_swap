/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:59:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 19:18:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	up_pos_max_b(t_data *d);
static void	body_while(t_data *d, t_index *index_lst, int next_index, int i);
static void	initilize(t_data *d, int *i, int *next_index, int *size_divided);

void	pb_sort(t_data *d, int min_id, int max_id, t_index *index_lst)
{
	int	i;
	int	next_index;
	int	size_divided;

	initilize(d, &i, &next_index, &size_divided);
	if (min_id < size_divided)
	{
		size_divided += min_id;
		min_id = 0;
	}
	while (i < size_divided)
	{				
		next_index = find_nex_index(min_id, max_id, index_lst, d);
		body_while(d, index_lst, next_index, i);
		exe_rr_rrr(d);
		pa_ot(d->cpy_stack_b, d->cpy_stack_a, d->size_b, d->size_a);
		pb(d);
		i++;
	}
	up_biggest_b(d);
	ex_pa_end(d, min_id, size_divided);
	if (min_id >= size_divided)
		pb_sort(d, min_id - size_divided, max_id - size_divided, index_lst);
}

static void	initilize(t_data *d, int *i, int *next_index, int *size_divided)
{
	*i = 0;
	*next_index = 0;
	*size_divided = 0;
	if (d->stock_size_a <= 50)
		*size_divided = d->stock_size_a;
	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
		*size_divided = d->stock_size_a / 5;
	if (d->stock_size_a > 150)
		*size_divided = d->stock_size_a / 10;
}

static void	body_while(t_data *d, t_index *index_lst, int next_index, int i)
{
	int	stock_nb_to_find;
	int	nearest_nb;

	stock_nb_to_find = 0;
	nearest_nb = 0;
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
		up_pos_max_b(d);
}

static void	up_pos_max_b(t_data *d)
{
	int	pos_max_b;

	pos_max_b = find_pos_max_b(d);
	while (d->cpy_stack_b[0] != pos_max_b)
		smart_b(d, pos_max_b);
}
