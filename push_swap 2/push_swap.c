/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/07 18:23:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_stack(t_data *stack);
void	test(t_data *d);
void	test_two(t_data *d);
void	test_three(t_data *d);
void	test_four(t_data *d);
void	test_five(t_data *d);
void	fusion_one_stack(t_data *d, t_tli **list_nb_sorted);
int		find_pos_nb_sort(t_data *d, t_tli *list_nb_sorted);
void	fusion_part_two(t_data *d, t_tli *list_nb_sorted);

int	main(int argc, char *argv[])
{
	t_data	d;
	t_tli	*list_nb_sorted;

	list_nb_sorted = NULL;
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

	fusion_one_stack(&d, &list_nb_sorted);
	fusion_part_two(&d, list_nb_sorted);
	fusion_one_stack(&d, &list_nb_sorted);
	fusion_part_two(&d, list_nb_sorted);
	fusion_one_stack(&d, &list_nb_sorted);
	fusion_part_two(&d, list_nb_sorted);
	fusion_one_stack(&d, &list_nb_sorted);
	fusion_part_two(&d, list_nb_sorted);
	fusion_one_stack(&d, &list_nb_sorted);

//	show_stack(&d);

	tli_clear(&list_nb_sorted);
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
	sort_first_five_da(d);
	sort_first_five_b(d);
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

void	fusion_one_stack(t_data *d, t_tli **list_nb_sorted)
{
	sort_first_five_da(d);
	for (int i = 0; i < 5; i++)
		ra(d);
	sort_first_five_da(d);
	for (int i = 0; i < 5; i++)
		rra(d);	

	int		i;
	int		j;
	int		nb_a;
	int		nb_b;
	int 	nb_sort;
	t_tli	*list_a;
	t_tli	*list_b;

	list_a = NULL;
	list_b = NULL;
	for (int i = 0; i < 5; i++)
		tli_add_back(&list_a, tli_new(d->stack_a[i]));
	for (int i = 5; i < 10; i++)
		tli_add_back(&list_b, tli_new(d->stack_a[i]));

	i = 0;
	j = 0;
	nb_a = 0;
	nb_b = 0;
	nb_sort = 1;

	if (list_a->content > list_b->content)
	{
		tli_add_back(list_nb_sorted, tli_new(list_a->content));
		tli_clear_one(&list_a, list_a->content);
		nb_a++;

	}
	else
	{
		tli_add_back(list_nb_sorted, tli_new(list_b->content));
		tli_clear_one(&list_b, list_b->content);
		nb_b++;

	}

//	printf("\n");
//	for (t_tli *cpy = list_a; cpy; cpy = cpy->next)
//		printf("%d ", cpy->content);
//	printf("\n");
//	for (t_tli *cpy = list_b; cpy; cpy = cpy->next)
//		printf("%d ", cpy->content);
//	printf("\n");
//		for (t_tli *cpy = list_nb_sorted; cpy; cpy = cpy->next)
//		printf("%d ", cpy->content);
//	printf("\n\n");


	
	while (nb_sort < 9)
	{
		if ((list_a && list_a->content > list_b->content && nb_a < 5) || (nb_b == 5))
		{
			while (d->stack_a[0] != list_a->content)
			{
				if (pos_in_stack(d->stack_a, d->size_a, tli_last(*list_nb_sorted)->content) > d->size_a / 2)
					rra(d);
				else
					ra(d);
			}
			
			while (d->stack_a[0] != tli_last(*list_nb_sorted)->content && d->stack_a[1] != list_a->content)
			{
				if (pos_in_stack(d->stack_a, d->size_a, tli_last(*list_nb_sorted)->content) > d->size_a / 2)
				{
					for (int i = d->size_a - pos_in_stack(d->stack_a, d->size_a, tli_last(*list_nb_sorted)->content); i; i--)
					{
						rra(d);
						sa(d);
					}
				}
				else
				{
					sa(d);
					if (d->stack_a[0] != tli_last(*list_nb_sorted)->content)
						ra(d);
				}
			}
			
			tli_add_back(list_nb_sorted, tli_new(list_a->content));
			tli_clear_one(&list_a, list_a->content);
			nb_a++;
		}
		else if (list_b)
		{
			while (d->stack_a[0] != list_b->content)
			{
				ra(d);
			}
			while (d->stack_a[0] != tli_last(*list_nb_sorted)->content && d->stack_a[1] != list_b->content)
			{
				if (pos_in_stack(d->stack_a, d->size_a, tli_last(*list_nb_sorted)->content) > d->size_a / 2)
				{
					for (int i = d->size_a - pos_in_stack(d->stack_a, d->size_a, tli_last(*list_nb_sorted)->content); i; i--)
					{
						rra(d);
						sa(d);
					}
				}
				else
				{
					sa(d);
					if (d->stack_a[0] != tli_last(*list_nb_sorted)->content)
						ra(d);
				}
			}
			tli_add_back(list_nb_sorted, tli_new(list_b->content));
			tli_clear_one(&list_b, list_b->content);
			nb_b++;
		}
		nb_sort++;		
	}
//		tli_clear(&list_a);
//		if (nb_b < 5)
//			tli_clear(&list_b);
}

int	find_pos_nb_sort(t_data *d, t_tli *list_nb_sorted)
{
	t_tli	*cpy;
	int		stock_pos;
	int		i;

	cpy = list_nb_sorted;
	stock_pos = -1;
	while (cpy)
	{
		i = pos_in_stack(d->stack_a, d->size_a, cpy->content);
		if(i < 10)
			stock_pos = i;
		cpy = cpy->next;
	}
	return (stock_pos);
}

void	fusion_part_two(t_data *d, t_tli *list_nb_sorted)
{
	while (find_pos_nb_sort(d, list_nb_sorted) != -1)
	{
		rra(d);
	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d\n", find_pos_nb_sort(d, list_nb_sorted));
//		rra(d);
//	}

}