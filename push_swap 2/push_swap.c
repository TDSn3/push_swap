/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/10 18:47:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_stack(t_data *stack);
void	test(t_data *d);
void	test_two(t_data *d);
void	test_three(t_data *d);
void	test_four(t_data *d);
void	test_five(t_data *d);
void	test_six(t_data *d);
void	test_seven(t_data *d);
void	test_height(t_data *d);
void	test_nine(t_data *d);
void	test_ten(t_data *d);
void	test_reverse(t_data *d);
void	test_ten_one(t_data *d);
void	test_ten_two(t_data *d);
void	test_ten_three(t_data *d);
void	test_ten_four(t_data *d);
void	test_ten_five(t_data *d);

int		find_nb_after_nb(t_data *d, int nb_stack);
t_index	*index_stack(t_data *d);

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

	index_stack(&d);

//	for (int i = 0; i < 11; i++)
//		test(&d);
//	for (int i = 0; i < 10; i++)
//		test_nine(&d);



//	for (int i = 0; i < 5; i++)
//	{
//		if (i % 2 == 0)
//		{	
//			test(&d);
//			test_reverse(&d);
//		}
//		else
//		{
//			test_reverse(&d);
//			test(&d);
//		}
//	}
//	for (int i = 0; i < 10; i++)
//		pa(&d);
//	test_ten_one(&d);
//	for (int i = 0; i < 10; i++)
//		pa(&d);
//	test_ten(&d);
//	for (int i = 0; i < 10; i++)
//		pa(&d);
//	test_ten_one(&d);
//	for (int i = 0; i < 10; i++)
//		pa(&d);
//	test_ten(&d);
//	for (int i = 0; i < 10; i++)
//		pa(&d);
//	test_ten_one(&d);
//
//
//
//	for (int i = 0; i < 20; i++)
//		pb(&d);
//	test_ten_two(&d);
//	for (int i = 0; i < 20; i++)
//		pb(&d);
//	test_ten_three(&d);
//	for (int i = 0; i < 20; i++)
//		pb(&d);
//
//
//
//	test_ten_four(&d);
//	test_ten_five(&d);

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
	while (i < 10)
	{
		if (( d->stack_a[0] < d->stack_b[0] && nb_a < 5 ) || (nb_b == 5))
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

void	test_six(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	int	stock_size_a;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	i = 0;
	stock_size_a = d->size_a;
	while (i < 10 + stock_size_a)
	{
		if (( d->stack_a[0] > d->stack_b[0] && nb_a < stock_size_a ) || (nb_b == 10))
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_seven(t_data *d)
{
	int	i;
	int	j;
	int	nb_a;
	int	nb_b;
	int	stock_size_a;

	i = 0;
	j = 0;
	nb_a = 0;
	nb_b = 0;
	stock_size_a = d->size_a;
	while (j < stock_size_a / 2)
	{
		while (i < 5)
		{
			pb(d);
			i++;
		}
		i = 0;
		sort_five_double(d);
		while (i < 5)
		{
			ra(d);
			i++;
		}
		i = 0;
		j += 5;
	}
}

void	test_height(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;

	i = 0;
	nb_a = 0;
	nb_b = 0;
	i = 0;
	while (i < 10)
	{
		if (( d->stack_b[0] > d->stack_a[0] && nb_b < 5 ) || (nb_a == 5))
		{
			rb(d);
			nb_b++;
		}
		else
		{
			pb(d);
			rb(d);
			nb_a++;
		}
		i++;
	}
}

void	test_nine(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	int	stock_size_a;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;	
	i = 0;
	stock_size_a = d->size_a;
	while (i < 10 + stock_size_a && ( d->size_b - 1 > -1 ))
	{
		if ( ( d->stack_a[0] < d->stack_b[0] && nb_a < stock_size_a ) || (nb_b == 10) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_ten(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;	
	i = 0;
	while (i < 20)
	{
		if ( ( d->stack_a[0] < d->stack_b[0] && nb_a < 10 ) || (nb_b == 10) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_reverse(t_data *d)
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
	sort_five_double_r(d);
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

void	test_ten_one(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;	
	i = 0;
	while (i < 20)
	{
		if ( ( d->stack_a[0] > d->stack_b[0] && nb_a < 10 ) || (nb_b == 10) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_ten_two(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;	
	i = 0;
	while (i < 40)
	{
		if ( ( d->stack_a[0] < d->stack_b[0] && nb_a < 20 ) || (nb_b == 20) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_ten_three(t_data *d)
{
	int	i;
	int	nb_a;
	int	nb_b;
	
	i = 0;
	nb_a = 0;
	nb_b = 0;	
	i = 0;
	while (i < 40)
	{
		if ( ( d->stack_b[0] < d->stack_a[0] && nb_b < 20 ) || (nb_a == 20) )
		{
			rb(d);
			nb_b++;
		}
		else
		{
			pb(d);
			rb(d);
			nb_a++;
		}
		i++;
	}
}

void	test_ten_four(t_data *d)
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
		if ( ( d->stack_a[0] < d->stack_b[0] && nb_a < 40 ) || (nb_b == 20) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

void	test_ten_five(t_data *d)
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
		if ( ( d->stack_a[0] < d->stack_b[0] && nb_a < 60 ) || (nb_b == 40) )
		{
			ra(d);
			nb_a++;
		}
		else
		{
			pa(d);
			ra(d);
			nb_b++;
		}
		i++;
	}
}

int	find_nb_after_nb(t_data *d, int nb_stack)
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

t_index	*index_stack(t_data *d)
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

	for (t_index *cpy = index_stack_a; cpy; cpy = cpy->next)
		printf("%d %d\n", cpy->content_index, cpy->content_stack);
	
	return (index_stack_a);
}
