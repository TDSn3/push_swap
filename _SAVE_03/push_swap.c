/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 10:13:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*dup_stack_a(t_data d);
int		*five_biggest_a(t_data *d, int *size);
void	next(t_data *d);
void	rotate_choice(t_data *d, int *size, int *tab);

int main(int argc, char *argv[])
{
	t_data d;
	OPER_ = 0;

	if (setup_struct(&d, argc, argv))
		return (1);

	next(&d);
	
	printf("\n");
	show_stack(d, argc);
	printf("\n\033[33;01m%d\033[00m \033[33;03moperation used\033[00m\n", OPER_);

	free(d.stack_a);
	free(d.stack_b);
	
	return (0);
}

void	next(t_data *d)
{
	int	size;
	int	*tab;

	while (d->size_a > 0)
	{
		tab = five_biggest_a(d, &size);
		rotate_choice(d,&size, tab);
		sort_first_five_b(*d);		
		free(tab);
	}
	while (d->size_b > 0)
	{
		pa(d);
	}
}

int	*five_biggest_a(t_data *d, int *size)
{
	int	i;
	int	j;
	int	*tab;

	if (d->size_a == 0)
		return (NULL);

	if (d->size_a > 5)
		*size = 5;
	else
		*size = d->size_a;

	tab = NULL;
	tab = malloc(sizeof(int) * (*size));
	if (!tab)
		return (NULL);

	i = 0;
	j = 0;
	while (i < *size)
	{
		tab[i] = d->stack_a[i];
		i++;
	}
	while (i < d->size_a)
	{
		while (j < *size)
		{
			if (tab[j] > d->stack_a[i])
			{
				tab[find_pos_max(tab, *size)] = d->stack_a[i];
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	sort_first_five_b(*d);
	return (tab);
}

void	rotate_choice(t_data *d, int *size, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < *size)
	{
		while (d->stack_a[i] != tab[j])
		{
			i++;
		}
		if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
		{
			while (d->stack_a[0] != tab[j])
			{
				rra(d);
			}
			pb(d);
		}
		else
		{
			while (d->stack_a[0] != tab[j])
			{
				ra(d);
			}
			pb(d);
		}
		i = 0;
		j++;
	}
}
