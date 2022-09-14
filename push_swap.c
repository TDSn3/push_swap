/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 12:21:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		order_b(int nb, t_data *d);
static int	find_nb_after_nb(t_data *d, int nb_stack);
static t_index	*index_stack(t_data *d);

int	main(int argc, char *argv[])
{
	t_data	d;
	t_index *index_lst;

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
	if (d.stock_size_a <= 50)
	{
		pb_sort(&d, 0, d.size_a, index_lst);
		while (d.size_b)
			pa(&d);	}
	if (d.stock_size_a <= 150 && d.stock_size_a > 50)
	{
		pb_sort(&d, d.size_a - (d.size_a / 5), d.size_a, index_lst);
		while (d.size_b)
			pa(&d);
	}
	if (d.stock_size_a > 150)
	{
		pb_sort(&d, d.size_a - (d.size_a / 10), d.size_a, index_lst);
		while (d.size_b)
			pa(&d);
	}
	clear_all(&d);
	tindex_clear(&index_lst);
	return (0);
}

int	order_b(int nb, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->size_b && d->size_b > 2)
	{
		if (nb < d->stack_b[i])
		{
			while (nb < d->stack_b[i])
			{
				i++;
			}
			return (i);
		}
		i++;
	}
	return (0);
}

static int	find_nb_after_nb(t_data *d, int nb_stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < d->size_a)
	{
		if (d->stack_a[i] < nb_stack)
			j++;
		i++;
	}
	return (j);
}

static t_index	*index_stack(t_data *d)
{
	int		i;
	int		index;
	t_index	*index_stack_a;

	index_stack_a = NULL;
	i = 0;
	while (i < d->size_a)
	{
		index = find_nb_after_nb(d, d->stack_a[i]);
		tindex_add_back(&index_stack_a, tindex_new(index, d->stack_a[i]));
		i++;
	}
	return (index_stack_a);
}