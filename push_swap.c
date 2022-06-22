/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 09:37:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		next(t_data *d);
static void	clear_all(t_data *d);
static void	next_while(t_data *d);

int	main(int argc, char *argv[])
{
	t_data	d;

	if (argc < 2)
		return (0);
	if (setup_struct(&d, argc, argv))
		return (1);
	if (ascending_order_tab(d.stack_a, d.size_a) == -1)
	{
		clear_all(&d);
		return (0);
	}
	next(&d);
	clear_all(&d);
	return (0);
}

void	next(t_data *d)
{
	int		i;
	t_tli	*tli_b_half_a;

	i = d->size_a / 2;
	if (d->size_a < 6)
	{
		sort_five(d);
		return ;
	}
	tli_b_half_a = NULL;
	tli_b_half_a = tli_setup_b_half_a(d, tli_b_half_a, i);
	tli_b_half_a = five_smaller_a(d, tli_b_half_a);
	rotate_choice(d, tli_b_half_a);
	next_while(d);
	while (d->size_b > 0)
		pa(d);
}

static void	next_while(t_data *d)
{
	int		nb_while;
	t_tli	*a;

	nb_while = 0;
	while (ascending_order_tab(d->stack_a, d->size_a) != -1)
	{
		if (nb_while % 8 == 0)
			setup_tli_ten(d);
		setup_tli_five(d);
		if (nb_while % 8 == 0)
		{
			a = tli_cpy(d->stock_tli_a_ten, d->firstpart_stock_a_ten);
			d->firstpart_stock_a_ten = a;
			a = tli_cpy(d->stock_tli_b_ten, d->firstpart_stock_b_ten);
			d->firstpart_stock_b_ten = a;
		}
		a = tli_cpy(d->stock_tli_a_five, d->firstpart_stock_a_five);
		d->firstpart_stock_a_five = a;
		a = tli_cpy(d->stock_tli_b_five, d->firstpart_stock_b_five);
		d->firstpart_stock_b_five = a;
		nb_while++;
	}	
}

static void	clear_all(t_data *d)
{
	tli_clear(&d->stock_tli_a_ten);
	tli_clear(&d->firstpart_stock_a_ten);
	tli_clear(&d->stock_tli_b_ten);
	tli_clear(&d->firstpart_stock_b_ten);
	tli_clear(&d->stock_tli_a_five);
	tli_clear(&d->firstpart_stock_a_five);
	tli_clear(&d->stock_tli_b_five);
	tli_clear(&d->firstpart_stock_b_five);
	free(d->stack_a);
	free(d->stack_b);
}
