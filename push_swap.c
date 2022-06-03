/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 19:19:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int			*dup_stack_a(t_data d);
void		test(t_data *d);
static int	comp_min(int *tab, int nb, int size);

int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);

	test(&d);
//	sort_five(d);
	printf("\n");
	show_stack(d, argc);
	free(d.stack_a);
	free(d.stack_b);
	return (0);
}

void	test(t_data *d)
{
	int	j;
	int	tab[5];
	int tab_i[5];

	j = 0;
	while (j < 5 || j != d->size_a)
	{
		tab[j] = d->stack_a[j];
		tab_i[j] = j;
		j++;
		continue ;
	}
	j = 0;
	while (j < d->size_a)
	{
		if (comp_min(tab, d->stack_a[j], j) != -1)
		{
			tab[j] = d->stack_a[j];
			tab_i[j] = j;
		}
		j++;
	}

//	sort_five(*d);
//	sort_first_five_b(*d);

/*
	while (d->size_b > 0)
	{
		sort_first_five_b(*d);
		while (i < 5)
		{
			pa(d);
			i++;
		}
		i = 0;
	}
*/

}

static int	comp_min(int *tab, int nb, int size)
{
	int	i;

	i= 0;
	if (size > 5)
		size = 5;
	while (i < size)
	{
		if (nb > tab[i])
			return (1);
		i++;
	}
	return (-1);
}
