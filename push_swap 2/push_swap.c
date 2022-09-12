/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/12 15:28:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_stack(t_data *stack);
int		find_index(int nb, t_index *index_lst, t_data *d);
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

	pb_sort(&d);
	
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

int	find_index(int nb, t_index *index_lst, t_data *d)
{
	int i;

	i = 0;
	while (i < d->stock_size_a)
	{
		if (nb == index_lst->content_stack)
			return (index_lst->content_index);
		i++;
	}
	return (-1);
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

