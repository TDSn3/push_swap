/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/08 19:47:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_stack(t_data *stack);
void	test(t_data *d);
void	test_two(t_data *d);
void	test_three(t_data *d);
void	test_four(t_data *d);
void	test_five(t_data *d);


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

	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	test(&d);
	
	test_two(&d);
//	test_two(&d);
//	test_two(&d);
//	test_two(&d);
//	test_two(&d);
//
//	test_three(&d);
//	test_three(&d);
//
//	test_four(&d);
//
//	test_five(&d);

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
	sort_five_double(d);
//	sort_first_five_da(d);
//	sort_first_five_b(d);
	while (i < 10)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_a < 5 ) || (nb_b == 5))
		{
			pb(d);
			rb(d);
			nb_a++;
		}
		else
		{
			rb(d);
			nb_b++;
		}
		i++;
	}
}

void	test_two(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;
	while (i < 10)
	{
		rrb(d);
		pa(d);
		i++;
	}	
	i = 0;
	while (i < 20)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_b < 10 ) || (nb_a == 10))
		{
			ra(d);
			nb_b++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_a++;
		}
		i++;
	}
}

void	test_three(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	while (i < 20)
	{
		rra(d);
		pb(d);
		i++;
	}
	i = 0;
	sort_five_double(d);
//	sort_first_five_da(d);
//	sort_first_five_b(d);
	while (i < 40)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_a < 20 ) || (nb_b == 20))
		{
			pb(d);
			rb(d);
			nb_a++;
		}
		else
		{
			rb(d);
			nb_b++;
		}
		i++;
	}
}

void	test_four(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	i = 0;
	while (i < 60)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_b < 20 ) || (nb_a == 40))
		{
			ra(d);
			nb_b++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_a++;
		}
		i++;
	}
}

void	test_five(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	i = 0;
	while (i < 100)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_b < 60 ) || (nb_a == 40))
		{
			ra(d);
			nb_b++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_a++;
		}
		i++;
	}
}

