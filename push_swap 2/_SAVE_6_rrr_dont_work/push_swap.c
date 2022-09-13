/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/13 12:35:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//static void	show_stack(t_data *stack);
int		order_b(int nb, t_data *d);

int	main(int argc, char *argv[])
{
	t_data	d;

	if (argc < 2)
		return (0);
	if (check_error(argc, argv) || setup_struct(&d, argc, argv))
		return (1);
	if (ascending_order_tab(d.stack_a, d.size_a) == -1)
	{
		free(d.stack_a);
		free(d.stack_b);
		return (0);
	}
	pb_sort(&d, 80, 100);
//	while (d.size_b)
//	{
//		pa(&d);
//	}
	free(d.stack_a);
	free(d.stack_b);
	return (0);
}
/*
static void	show_stack(t_data *d)
{
	int	i;

	i = 0;
	printf("\nstack_a : ");
	while (i < d->size_a)
	{
		printf("%d ", d->stack_a[i]);
		i++;
	}
	i = 0;
	printf("\nstack_b : ");
	while (i < d->size_b)
	{
		printf("%d ", d->stack_b[i]);
		i++;
	}
	printf("\n\n");
}
*/
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

