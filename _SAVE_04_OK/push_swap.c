/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/15 15:48:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	next(t_data *d);

t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a);

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
//	int		i;
	t_tli	*tli_b;
//	t_tli	*tli_a;

//	i = d->size_a / 2;

	if (d->size_a < 6)
	{
		sort_five(d);
		return ;
	}

	while (d->size_a > 0)
	{
		tli_b = NULL;
		tli_b = setup_tli(d, tli_b);
		tli_b = five_smaller_a(d, tli_b);
		rotate_choice(d, tli_b);
//		tli_a = NULL;
//		tli_a = setup_tli(d, tli_a);
//		tli_a = five_biggest_a(d, tli_a);
//		up_biggest_lti_a(d, tli_a);

		sort_first_five_b(d);	
//		sort_first_five_a(d);

//		sort_five_double(d);

	}
	while (d->size_b > 0)
		pa(d);
}

t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a)
{
	t_tli	*tli_i;

	tli_i = tli;
	while (tli_i)
	{
		tli_add_back(&stock_tli_a, tli_new(tli->content));
		tli_i = tli_i->next; 
	}
	return (stock_tli_a);
}