/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/10 13:13:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	next(t_data *d);

t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a_ten);

int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);

	next(&d);
	
	printf("\n");
	show_stack(d, argc);
	printf("\n\033[33;01m%d\033[00m \033[33;03moperation used\033[00m\n", d.OPER_USED);	// TO DELETE //

	free(d.stack_a);
	free(d.stack_b);
	
	return (0);
}

void	next(t_data *d)
{
	int		i;
	int		nb_while;

	t_tli	*tli_a_ten;
	t_tli	*tli_a_five;
	t_tli	*tli_b_ten;
	t_tli	*tli_b_five;
	
	t_tli	*stock_tli_a_ten;
	t_tli	*firstpart_stock_a_ten;
	t_tli	*stock_tli_b_ten;
	t_tli	*firstpart_stock_b_ten;
	
	t_tli	*stock_tli_a_five;
	t_tli	*firstpart_stock_a_five;
	t_tli	*stock_tli_b_five;
	t_tli	*firstpart_stock_b_five;
	
	i = d->size_a / 2;
	nb_while = 0;

	if (d->size_a < 6)
	{
		sort_five(d);
		return ;
	}

	stock_tli_a_ten = NULL;
	firstpart_stock_a_ten = NULL;
	stock_tli_b_ten = NULL;
	firstpart_stock_b_ten = NULL;

	stock_tli_a_five = NULL;
	firstpart_stock_a_five = NULL;
	stock_tli_b_five = NULL;
	firstpart_stock_b_five = NULL;

	t_tli	*tli_b_half_a;
	tli_b_half_a = NULL;
	
	tli_b_half_a = tli_setup_b_half_a(d, tli_b_half_a, i);
	tli_b_half_a = five_smaller_a(d, tli_b_half_a);
	rotate_choice(d, tli_b_half_a);

//	while (d->size_a > i)
//	while (nb_while < 8)
	while (ascending_order_tab(d->stack_a, d->size_a) != -1 && d->OPER_USED < 15000)
	{


		if (nb_while % 8 == 0)
		{
			tli_a_ten = NULL;
			tli_a_ten = tli_setup_a_ten(d, tli_a_ten, stock_tli_a_ten);
			tli_a_ten = five_biggest_a(d, tli_a_ten, stock_tli_a_ten);		
			stock_tli_a_ten = tli_cpy(tli_a_ten, stock_tli_a_ten);
			up_biggest_lti_a(d, tli_a_ten, firstpart_stock_a_ten);

			tli_b_ten = NULL;
			tli_b_ten = tli_setup_b_ten(d, tli_b_ten, stock_tli_b_ten);
			tli_b_ten = five_smaller_b(d, tli_b_ten, stock_tli_b_ten);		
			stock_tli_b_ten = tli_cpy(tli_b_ten, stock_tli_b_ten);
			up_smaller_tli_b(d, tli_b_ten, firstpart_stock_b_ten);
		}

		tli_a_five = NULL;
		tli_a_five = tli_setup_a_five(d, tli_a_five, stock_tli_a_five);
		tli_a_five = five_biggest_a(d, tli_a_five, stock_tli_a_five);		
		stock_tli_a_five = tli_cpy(tli_a_five, stock_tli_a_five);
		up_biggest_lti_a(d, tli_a_five, firstpart_stock_a_five);

		tli_b_five = NULL;
		tli_b_five = tli_setup_b_five(d, tli_b_five, stock_tli_b_five);
		tli_b_five = five_smaller_b(d, tli_b_five, stock_tli_b_five);		
		stock_tli_b_five = tli_cpy(tli_b_five, stock_tli_b_five);
		up_smaller_tli_b(d, tli_b_five, firstpart_stock_b_five);
		
		sort_five_double(d);
		
		if (nb_while % 8 == 0)
		{
			firstpart_stock_a_ten = tli_cpy(stock_tli_a_ten, firstpart_stock_a_ten);
			firstpart_stock_b_ten = tli_cpy(stock_tli_b_ten, firstpart_stock_b_ten);
		}
			
		firstpart_stock_a_five = tli_cpy(stock_tli_a_five, firstpart_stock_a_five);
		firstpart_stock_b_five = tli_cpy(stock_tli_b_five, firstpart_stock_b_five);
		nb_while++;
	}
	while (d->size_b > 0)
		pa(d);

	tli_clear(&stock_tli_a_ten);
	tli_clear(&firstpart_stock_a_ten);
	tli_clear(&stock_tli_b_ten);
	tli_clear(&firstpart_stock_b_ten);

	tli_clear(&stock_tli_a_five);
	tli_clear(&firstpart_stock_a_five);
	tli_clear(&stock_tli_b_five);
	tli_clear(&firstpart_stock_b_five);

}

t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a_ten)
{
	t_tli	*tli_i;

	tli_i = tli;
	while (tli_i)
	{
		tli_add_back(&stock_tli_a_ten, tli_new(tli_i->content));
		tli_i = tli_i->next; 
	}
	return (stock_tli_a_ten);
}