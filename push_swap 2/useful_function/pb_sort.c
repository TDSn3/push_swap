/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:59:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/14 09:53:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	find_nb(int index, t_index *index_lst);
static t_index	*index_stack(t_data *d);
static int	smart_insertion(t_data *d, int nb);
static int	find_pos_max_b(t_data *d);
static int	find_nb_after_nb(t_data *d, int nb_stack);
static int	find_index(int nb, t_index *index_lst);
static int	find_nex_index(int min_index, int max_index, t_index *index_lst, t_data *d);
static int	find_pos_a(int nb, t_data *d);
//static void	show_stack(t_data *d);

void	pb_sort(t_data *d, int min_index, int max_index)
{
	int	i =  /*d->size_a / 2*/ 0;
	int	stock_nb_to_find;
	int	nearest_nb;
	int	pos_max_b;
	int	next_index;
	t_index	*index_lst;
	int	size_divided;

	int	rra_i;
	int ra_i;
	int	rrb_i;
	int rb_i;

	rra_i = 0;
	ra_i = 0;
	rrb_i = 0;
	rb_i = 0;
	if (d->stock_size_a <= 50)
		size_divided = d->stock_size_a;
	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
		size_divided = d->stock_size_a / 5;
	if (d->stock_size_a > 150)
		size_divided = d->stock_size_a / 10;

	if (min_index < size_divided)
	{
		size_divided += min_index;
		min_index = 0;
	}
		

	index_lst = index_stack(d);

//	if (d->stock_size_a % 2 != 0)
//		i++;
		
	while (i < /*d->stock_size_a*/ size_divided) // ICI 20 pour /5
	{				
		next_index = find_nex_index(min_index, max_index, index_lst, d);
		if (d->stack_a[0] != next_index)
		{
				if (pos_in_stack(d->stack_a, d->size_a, next_index) > d->size_a / 2)
				{
					while (d->cpy_stack_a[0] != next_index)
					{
						rra_ot(d->cpy_stack_a, d->size_a);
						rra_i++;
					}
				}
				else
				{
					while (d->cpy_stack_a[0] != next_index)
					{
						ra_ot(d->cpy_stack_a, d->size_a);
						ra_i++;
					}
				}
		}
		stock_nb_to_find = find_nb(i, index_lst);
		nearest_nb = smart_insertion(d, d->cpy_stack_a[0]);
		if (nearest_nb != d->cpy_stack_a[0])
		{
			while (d->cpy_stack_b[0] != nearest_nb)
			{
				if (pos_in_stack(d->cpy_stack_b, d->size_b, nearest_nb) > d->size_b / 2)
				{
					while (d->cpy_stack_b[0] != nearest_nb)
					{
						rra_ot(d->cpy_stack_b, d->size_b);
						rrb_i++;
					}
				}
				else
				{
					while (d->cpy_stack_b[0] != nearest_nb)
					{
						ra_ot(d->cpy_stack_b, d->size_b); 
						rb_i++;	
					}
				}
			}
		}
		else
		{
			pos_max_b = find_pos_max_b(d);
			while (d->cpy_stack_b[0] != pos_max_b)
			{
				if (pos_in_stack(d->cpy_stack_b, d->size_b, pos_max_b) > d->size_b / 2)
				{
					while (d->cpy_stack_b[0] != pos_max_b)
					{
						rra_ot(d->cpy_stack_b, d->size_b);
						rrb_i++;
					}
				}
				else
				{
					while (d->cpy_stack_b[0] != pos_max_b)
					{
						ra_ot(d->cpy_stack_b, d->size_b);
						rb_i++;	
					}
				}
			}
		}

		while (ra_i > 0 || rb_i > 0 || rra_i > 0 || rrb_i > 0)
		{
			if (rra_i && rrb_i)
			{
				rrr(&d);
				rra_i--;
				rrb_i--;
				continue ;
			}
			else if (ra_i && rb_i)
			{
				rr(&d);
				ra_i--;
				rb_i--;
				continue ;
			}
			else if (ra_i)
			{
				ra(d);
				ra_i--;
			}
			else if (rb_i)
			{
				rb(d);
				rb_i--;
			}
			else if (rra_i)
			{
				rra(d);
				rra_i--;
			}
			else if (rrb_i)
			{
				rrb(d);
				rrb_i--;
			}
		}
		
		pa_ot(d->cpy_stack_b, d->cpy_stack_a, d->size_b, d->size_a);
		pb(d);

		i++;
	}
	pos_max_b = find_pos_max_b(d);
	while (d->stack_b[0] != pos_max_b)
	{
		if (pos_in_stack(d->stack_b, d->size_b, pos_max_b) > d->size_b / 2)
			while (d->stack_b[0] != pos_max_b)
			{
				rra_ot(d->cpy_stack_b, d->size_b);
				rrb(d);
			}
		else
			while (d->stack_b[0] != pos_max_b)
			{
				ra_ot(d->cpy_stack_b, d->size_b);
				rb(d);
			}			
	}
	
	if (min_index == size_divided * 3 && d->stock_size_a > 150)
	{	
		while (d->size_b)
		{
			pa_ot(d->cpy_stack_a, d->cpy_stack_b, d->size_a, d->size_b);
			pa(d);
		}
	}
	if (min_index == size_divided && d->stock_size_a <= 150 && d->stock_size_a > 50)
	{	
		while (d->size_b)
		{
			pa_ot(d->cpy_stack_a, d->cpy_stack_b, d->size_a, d->size_b);
			pa(d);
		}
	}

	if (d->stock_size_a <= 150 && d->stock_size_a > 50)
		d->rest_div += d->stock_size_a % 5;
	if (d->stock_size_a > 150)
		d->rest_div += d->stock_size_a % 10;

	if (min_index >= size_divided)
		pb_sort(d, min_index - size_divided, max_index - size_divided);

}
static int	find_nb(int index, t_index *index_lst)
{
	t_index *cpy;

	cpy = index_lst;
	while (cpy)
	{
		if (index == cpy->content_index)
			return (cpy->content_stack);
		else
			cpy = cpy->next;
	}
	return (-1);
}

static int	smart_insertion(t_data *d, int nb)
{
	int	stock_min;
	int i;
	

	i = 0;
	stock_min = nb;

	while (i < d->size_b)
	{
		if (stock_min == nb)
		{
			if (d->cpy_stack_b[i] < nb)
			{
				stock_min = d->cpy_stack_b[i];
			}
		}
		else if (stock_min != nb)
		{
			if (d->cpy_stack_b[i] > stock_min && d->cpy_stack_b[i] < nb)
			{
				stock_min = d->cpy_stack_b[i];
			}
		}
		i++;
	}
	return (stock_min);
}

static int	find_nb_after_nb(t_data *d, int nb_stack)
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

static t_index	*index_stack(t_data *d)
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
	return (index_stack_a);
}

static int	find_pos_max_b(t_data *d)
{
	int i;
	int	stock_max;

	i = 1;
	stock_max = d->cpy_stack_b[0];
	while (i < d->size_b)
	{
		if (d->cpy_stack_b[i] > stock_max)
			stock_max = d->cpy_stack_b[i];
		i++;
	}
	return (stock_max);
}

static int	find_index(int nb, t_index *index_lst)
{
	t_index *cpy;

	cpy = index_lst;

	while (cpy)
	{
		if (nb == cpy->content_stack)
			return (cpy->content_index);	
		cpy = cpy->next;	
	}
	return (-1);
}

static int	find_nex_index(int min_index, int max_index, t_index *index_lst, t_data *d)
{
	int	i;
	int	stock_one;
	int	stock_two;

	stock_one = -1;
	stock_two = -1;
	if (find_index(d->stack_a[0], index_lst) >= min_index && find_index(d->stack_a[0], index_lst) < max_index)
		return (d->stack_a[0]);
	i = 1;
	while (i < d->size_a)
	{
		if (find_index(d->stack_a[i], index_lst) >= min_index && find_index(d->stack_a[i], index_lst) < max_index)
		{
			stock_one = d->stack_a[i];
			break ;
		}
		i++;
	}
	i = d->size_a - 1;
	while (i)
	{
		if (find_index(d->stack_a[i], index_lst) >= min_index && find_index(d->stack_a[i], index_lst) < max_index)
		{
			stock_two = d->stack_a[i];
			break ;
		}
		i--;
	}
	if (find_pos_a(stock_one, d) < d->size_a - find_pos_a(stock_two, d))
		return (stock_one);
	else
		return (stock_two);
}

static int	find_pos_a(int nb, t_data *d)
{
	int i;

	i = 0;
	while (i < d->size_a)
	{
		if (nb == d->stack_a[i])
			return (i);
		i++;
	}
	return (-1);
}
