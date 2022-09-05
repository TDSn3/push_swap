/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/05 17:08:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define SIZE 10

void	show_stack(t_data *stack);
void	test(t_data *d);

int	main(int argc, char *argv[])
{
	t_data	d;

	if (argc < 2)
		return (0);
	if (check_error(argc, argv) || setup_struct(&d, argc, argv))
		return (1);

	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);

//	show_stack(&d);

	free(d.stack_a);
	free(d.stack_b);
	return (0);
}

void	show_stack(t_data *d)
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

void	test(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	while (i < 5)
	{
		pb(d);
		i++;
	}
	i = 0;
	sort_first_five_da(d);
	sort_first_five_b(d);
	while (i < 10)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_a < 5 ) || (nb_b == 5))
		{
			pb(d);
			rb(d);
			nb_a++;
		}
		else if (d->stack_a[0] < d->stack_b[0] && nb_b < 5)
		{
			rb(d);
			nb_b++;
		}
		i++;
	}
}