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
void	recursive_test(t_data *d, int next_operation, int *tab, int i, int prev_operation, int nb_rotate);
int		copy_stack_a_struct(t_data *d);
int		comp_stack_a(t_data d);
void	reset_satck_a(t_data *d);
int		*dup_stack_a(t_data d);
int		comp_stack_a_lst(t_data d);
void 	miniclean_lst(t_data *d, int pos);
void 	change_stack_a(t_data *d, int *save);

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
	recursive_test(&d, 1, d.copy_stack_a, 0, 0, 0);


	if (d.lst_copy_stack)
		ft_lst_tab_clear(&d.lst_copy_stack);
	free(d.copy_stack_a);
	free(d.stack_a);
	free(d.stack_b);

	return (0);
}

void	recursive_test(t_data *d, int next_operation, int *tab, int i, int prev_operation, int nb_rotate)
{	
	int *save;

	if (d->recu_on == 0 && i > d->stock_recu_i - 1) // stop si le nombre d'opération effectué dépasse un nombre de suite déjà effectué ayant reussi à trier.
	{
		printf(" \033[35m{LOST_(%d)-%d.%d}\033[00m ", i, prev_operation, next_operation);
		if (prev_operation == 1)
			sa(d);
		else if (prev_operation == 2)
			rra(d);
		else if (prev_operation == 4)
			ra(d);
		miniclean_lst(d, i);
		return;
	}
	i++; // compte le nombre d'opération
	printf("\n(%d \033[2;3m%d\033[00m)", i, prev_operation);
	if (ascending_order_a(*d) == -1 && d->size_b == 0) // stop si la stack est trié
	{
		printf(" ");
		show_stacks(*d, 6);
		if (prev_operation == 1)
			sa(d);
		else if (prev_operation == 2)
			rra(d);
		else if (prev_operation == 4)
			ra(d);	
		printf(" \033[33;01m[SORTED in %d]\033[00m ", i - 1);
		d->stock_recu_i = i;
		d->recu_on = 0;
		miniclean_lst(d, i);
		return ;
	}
	if (next_operation == 1) // SA
	{
		printf("+1 ");
		printf(" ");
		show_stacks(*d, 6);
		printf(" -> ");
		sa(d);
		if (comp_stack_a(*d) || comp_stack_a_lst(*d))
		{
			sa(d);
			printf(" \033[31m{BAD_WAY}\033[00m "); // ROUGE
			miniclean_lst(d, i);
			return ;	
		}
		ft_lst_tab_add_back(&d->lst_copy_stack, ft_lst_tab_new(dup_stack_a(*d), i));
		if (!ft_lst_tab_last(d->lst_copy_stack))
			exit ( 1 );
		printf(" ");
		show_stacks(*d, 6);
		save = dup_stack_a(*d);
		recursive_test(d, 2, tab, i, 1, nb_rotate);
		if (d->recu_on == 0 && i + 1 > d->stock_recu_i)
			return ;
		change_stack_a(d, save);
		recursive_test(d, 4, tab, i, 1, nb_rotate);
	}
	if (next_operation == 2) // RA
	{
		printf("+2 ");
		printf(" ");
		show_stacks(*d, 6);
		printf(" -> ");
		ra(d);
		if (prev_operation == 2)
			nb_rotate++;
		else
			nb_rotate = 0;
		if (comp_stack_a(*d) || comp_stack_a_lst(*d) || nb_rotate == d->size_a)
		{
			rra(d);
			printf(" \033[36m{BAD_WAY}\033[00m "); // CYAN
			miniclean_lst(d, i);
			return ;	
		}
		printf(" ");
		show_stacks(*d, 6);
		save = dup_stack_a(*d);
		if (d->recu_on == 0 && i + 1 > d->stock_recu_i)
			return ;
		recursive_test(d, 2, tab, i, 2, nb_rotate);
		if (d->recu_on == 0 && i + 1 > d->stock_recu_i)
			return ;
		change_stack_a(d, save);
		recursive_test(d, 1, tab, i, 2, nb_rotate);
	}
	if (next_operation == 4) // RRA
	{
		printf("+4 ");
		printf(" ");
		show_stacks(*d, 6);
		printf(" -> ");
		rra(d);	
		if (prev_operation == 4)
			nb_rotate++;
		else
			nb_rotate = 0;
		if (comp_stack_a(*d) || comp_stack_a_lst(*d) || nb_rotate == d->size_a)
		{
			ra(d);
			printf(" \033[34m{BAD_WAY}\033[00m "); // BLEU
			miniclean_lst(d, i);
			return ;	
		}
		printf(" ");
		show_stacks(*d, 6);
		save = dup_stack_a(*d);
		if (d->recu_on == 0 && i + 1 > d->stock_recu_i)
			return ;
		recursive_test(d, 4, tab, i, 4, nb_rotate);
		if (d->recu_on == 0 && i + 1 > d->stock_recu_i)
			return ;
		change_stack_a(d, save);
		recursive_test(d, 1, tab, i, 4, nb_rotate);
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

int	comp_stack_a_lst(t_data d)
{
	t_tab	*nextl;
	int	i;
	int j;

	i = 0;
	j = 0;
	nextl = d.lst_copy_stack;
	while (nextl)
	{
		if (nextl->content)
		{
			while (i < d.size_a)
			{
				if (d.stack_a[i] == nextl->content[i])
					j++;
				i++;
			}
			if (j == d.size_a)
			return (1);
			i = 0;
			j = 0;
		}
		nextl = nextl->next;
	}
	return (0);
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
//		if (i - 1 < d.size_a || i - 1 < d.size_b)
//			printf("\n");
	}
//	printf("- -\na b\n\n");	
}

void 	miniclean_lst(t_data *d, int pos)
{
	t_tab	*nextl;

	nextl = d->lst_copy_stack;
	while (nextl)
	{
		if (nextl->pos > pos)
		{
			free(nextl->content);
			nextl->content = NULL;
		}
		nextl = nextl->next;
	}
}

void 	change_stack_a(t_data *d, int *save)
{
	int	i;

	i = 0;
	while (i < d->size_a)
	{
		d->stack_a[i] = save[i];
		i++;
	}	
}