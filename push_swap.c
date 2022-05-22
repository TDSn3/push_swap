/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	show_stacks(t_data d, int argc);
void	recursive_test(t_data *d, int next_operation, int *tab, int i, int prev_operation);
int		copy_stack_a_struct(t_data *d);
int		comp_stack_a(t_data d);
void	reset_satck_a(t_data *d);
int		*dup_stack_a(t_data d);


int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);
	if (ascending_order_a(d) > -1)
		printf("\nIt is not sorted, in th stack a : %d is bigger than %d", d.stack_a[ascending_order_a(d)], d.stack_a[ascending_order_a(d) + 1]);
	printf("\nBiggest num in stack a is %d, [%d]\n\n", d.stack_a[find_max_a(d)], find_max_a(d));
	show_stacks(d, argc);

	copy_stack_a_struct(&d);
	d.recu_on = 1;
	recursive_test(&d, 2, d.copy_stack_a, 0, 0);

	if (d.lst_copy_stack)
		ft_lst_tab_clear(&d.lst_copy_stack);
	free(d.copy_stack_a);
	free(d.stack_a);
	free(d.stack_b);

	return (0);
}

void	recursive_test(t_data *d, int next_operation, int *tab, int i, int prev_operation)
{
	if (d->recu_on == 0 && i > d->stock_recu_i - 1) // stop si le nombre d'opération effectué dépasse un nombre de suite déjà effectué ayant reussi à trier.
	{
		printf(" \033[35m{LOST_(%d)-%d.%d}\033[00m ", i, prev_operation, next_operation);
		if (prev_operation == 1)
			sa(d);
		else if (prev_operation == 2)
			rra(d);
		else if (prev_operation == 4)
			ra(d);	
		return;
	}
	i++; // compte le nombre d'opération

	printf("(%d)", i);
	if (ascending_order_a(*d) == -1 && d->size_b == 0) // stop si la stack est trié
	{
		if (prev_operation == 1)
			sa(d);
		else if (prev_operation == 2)
			rra(d);
		else if (prev_operation == 4)
			ra(d);	
		printf(" \033[33;01m[SORTED in %d]\033[00m ", i - 1);
		d->stock_recu_i = i;
		d->recu_on = 0;
		return ;
	}
	if (next_operation == 1) // SA
	{
		printf("+1 ");
		sa(d);
		ft_lst_tab_add_back(&d->lst_copy_stack, ft_lst_tab_new(dup_stack_a(*d)));
		if (!ft_lst_tab_last(d->lst_copy_stack))
			exit ( 1 );
		if (comp_stack_a(*d))
		{
			sa(d);
			printf(" \033[31m{BAD_WAY}\033[00m "); // ROUGE
			return ;	
		}
		recursive_test(d, 2, tab, i, 1);
		recursive_test(d, 4, tab, i, 1);
	}
	if (next_operation == 2) // RA
	{
		printf("+2 ");
		ra(d);
		if (comp_stack_a(*d))
		{
			rra(d);
			printf(" \033[36m{BAD_WAY}\033[00m "); // CYAN
			return ;	
		}
		recursive_test(d, 2, tab, i, 2);
		if (prev_operation != 1)
			recursive_test(d, 1, tab, i, 2);
	}
	if (next_operation == 4) // RRA
	{
		printf("+4 ");
		rra(d);	
		if (comp_stack_a(*d))
		{
			ra(d);
			printf(" \033[34m{BAD_WAY}\033[00m "); // BLEU
			return ;	
		}
		recursive_test(d, 4, tab, i, 4);
		if (prev_operation != 1)
			recursive_test(d, 1, tab, i, 4);
	}
}

int	copy_stack_a_struct(t_data *d)
{
	int	i;

	i = 0;
	if (d->size_a > 0)
	{
		d->copy_stack_a = malloc(sizeof(int) * d->size_a);
		if (!d->copy_stack_b)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		while (i < d->size_a)
		{
			d->copy_stack_a[i] = d->stack_a[i];
			i++;
		}
	}
	if (d->size_b > 0)
	{
		i = 0;
		d->copy_stack_b = malloc(sizeof(int) * d->size_b);
		if (!d->copy_stack_a)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		while (i < d->size_a)
		{
			d->copy_stack_a[i] = d->stack_a[i];
			i++;
		}
	}
	return (0);
}

int	comp_stack_a(t_data d)
{
	int	i;

	i = 0;
	while (i < d.size_a)
	{
		if (d.stack_a[i] != d.copy_stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

// LA SUITE 

int	comp_stack_a_lss(t_data d)
{
	int	i;

	i = 0;
	while (i < ft_lst_tab_size(&d.lst_copy_stack))
	{
		if (d.stack_a[i] != d.copy_stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	*dup_stack_a(t_data d)
{
	int	i;
	int	*tab;

	i = 0;
	if (d.size_a > 0)
	{
		tab = malloc(sizeof(int) * d.size_a);
		if (!tab)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		while (i < d.size_a)
		{
			tab[i] = d.stack_a[i];
			i++;
		}
		return (tab);
	}
	return (NULL);
}

void	reset_satck_a(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->size_a)
	{
		d->stack_a[i] = d->copy_stack_a[i];
		i++;
	}
}

void	show_stacks(t_data d, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		if (i - 1 < d.size_a)
			printf("%d", d.stack_a[i - 1]);
		else if (i - 1 < d.size_b)
			printf(" ");
		if (i - 1 < d.size_b)
			printf(" %d", d.stack_b[i - 1]);
		if (i - 1 < d.size_a || i - 1 < d.size_b)
			printf("\n");
	}
	printf("- -\na b\n\n");	
}