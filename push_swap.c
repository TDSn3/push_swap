/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 18:35:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	sort_all(t_data *d, t_index *index_lst);

int	main(int argc, char *argv[])
{
	t_data	d;
	t_index	*index_lst;

	index_lst = NULL;
	if (argc < 2)
		return (0);
	if (check_error(argc, argv) || setup_struct(&d, argc, argv))
		return (1);
	if (ascending_order_tab(d.stack_a, d.size_a) == -1)
	{
		clear_all(&d);
		return (0);
	}
	if (d.stock_size_a < 6)
	{
		sort_first_five_a(&d);
		clear_all(&d);
		return (0);
	}
	index_lst = index_stack(&d);
	if (!index_lst)
	{
		clear_all(&d);
		printf("ERRRO\n");
		exit (-1);
	}
	sort_all(&d, index_lst);
	clear_all(&d);
	tindex_clear(&index_lst);
	return (0);
}

static void	sort_all(t_data *d, t_index *index_lst)
{
	if (d->stock_size_a <= 50)
	{
		pb_sort(d, 0, d->size_a, index_lst);
		while (d->size_b)
			pa(d);
	}
	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
	{
		pb_sort(d, d->size_a - (d->size_a / 5), d->size_a, index_lst);
		while (d->size_b)
			pa(d);
	}
	if (d->stock_size_a > 150)
	{
		pb_sort(d, d->size_a - (d->size_a / 10), d->size_a, index_lst);
		while (d->size_b)
			pa(d);
	}
}
