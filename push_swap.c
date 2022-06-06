/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/06 16:10:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*dup_stack_a(t_data d);
int		*five_biggest_a(t_data *d, int *size);
void	next(t_data *d);
void	rotate_choice(t_data *d, int *size, int **tab);
int		choice_better_give_nb(t_data *d, int nb);
int		*choice_better(t_data *d, int *size, int *tab);
int		*select_and_del(int *size, int **tab, int nb_del);
int		*ft_strdup2(int *s, int size);
size_t	ft_strlcpy2(int *dst, int *src, int size);


int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);

	next(&d);
	
	printf("\n");
	show_stack(d, argc);
	printf("\n\033[33;01m%d\033[00m \033[33;03moperation used\033[00m\n", d.OPER_USED);	// TO DELETE //

	free(d.stack_a);
	free(d.stack_b);
	
	return (0);
}

void	next(t_data *d)
{
	int	size;
	int	*tab;

//	while (d->size_a > 0)
//	{
		tab = five_biggest_a(d, &size);
		rotate_choice(d,&size, &tab);
//		sort_first_five_b(*d);		
		free(tab);
//		sort_first_five_a(*d);
//	}
//	while (d->size_b > 0)
//	{
//		pa(d);
//	}
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
	return (tab);
}

void	rotate_choice(t_data *d, int *size, int **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	
	int	ii;

	ii = 1;
	t_tli *tli;

	tli = tli_new((*tab)[0]);

	t_tli	*tli_cpy;

	tli_cpy = tli;
	while (ii < *size)
	{
		tli_add_back(&tli, tli_new((*tab)[ii]));
		ii++;
	}

	for (t_tli *x = tli ; x ; x = x->next)
		printf("\n%d", x->content);

	tli_clear(&tli);

	while (j < *size)
	{
		while (d->stack_a[i] != (*tab)[j] && i < d->size_a)
		{
			i++;
		}
		if (pos_in_stack(d->stack_a, d->size_a, d->stack_a[i]) > d->size_a / 2)
		{
			while (d->stack_a[0] != (*tab)[j] && k < d->size_a)
			{
				rra(d);
				k++;
			}
			k = 0;
			pb(d);
		}
		else
		{
			while (d->stack_a[0] != (*tab)[j] && k < d->size_a)
			{
				ra(d);
				k++;
			}
			k = 0;
			pb(d);
		}
		i = 0;
		j++;
	}
}

int	*choice_better(t_data *d, int *size, int *tab)
{
	int	i;
	int nb_pos;

	i = 1;
	nb_pos = choice_better_give_nb(d, tab[0]);
	while (i < *size)
	{
		if (choice_better_give_nb(d, tab[i]) < nb_pos)
			nb_pos = choice_better_give_nb(d, tab[i]);
		i++;
	}
	return (&tab[nb_pos]);
}

int	choice_better_give_nb(t_data *d, int nb)
{
	int	i;
	int top;
	int	bot;
	int	size_div;

	i = 0;
	top = 0;
	bot = d->size_a - 1;
	size_div = d->size_a / 2;
	
	if (d->size_a % 2 == 1 && d->size_a > 2)
		size_div++;

	while (i < size_div)
	{
		if (d->stack_a[top] == nb)
			return (i);
		if (d->stack_a[bot] == nb)
			return (i + 1);
		i++;
		top++;
		bot--;
	}
	return (0);
}
/*
int	*select_and_del(int *size, int **tab, int nb_del, t_list lst)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back()
	}
}
*/
int	*ft_strdup2(int *s, int size)
{
	int	*copy;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return (NULL);
	ft_strlcpy2(copy, s, size);
	return (copy);
}

size_t	ft_strlcpy2(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (0);
}