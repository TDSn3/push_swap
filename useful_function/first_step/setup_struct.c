/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/18 17:27:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	calloc_all(t_data *d, int argc);
static void	initialize(t_data *d, int argc);

int	setup_struct(t_data *d, int argc, char **argv)
{
	int	i;

	i = 1;
	if (calloc_all(d, argc))
		return (return_error());
	initialize(d, argc);
	while (i < argc)
	{
		d->stack_a[i - 1] = ft_atoi(argv[i]);
		d->cpy_stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_repeat(d))
	{
		free(d->stack_a);
		free(d->stack_b);
		free(d->cpy_stack_a);
		free(d->cpy_stack_b);
		return (return_error());
	}
	return (0);
}

static int	calloc_all(t_data *d, int argc)
{
	d->stack_a = ft_calloc(sizeof(int), argc - 1);
	if (!d->stack_a)
		return (1);
	d->stack_b = ft_calloc(sizeof(int), argc - 1);
	if (!d->stack_b)
	{
		free(d->stack_a);
		return (1);
	}
	d->cpy_stack_a = ft_calloc(sizeof(int), argc - 1);
	if (!d->cpy_stack_a)
	{
		free(d->stack_a);
		free(d->stack_b);
		return (1);
	}
	d->cpy_stack_b = ft_calloc(sizeof(int), argc - 1);
	if (!d->cpy_stack_b)
	{
		free(d->stack_a);
		free(d->stack_b);
		free(d->cpy_stack_a);
		return (1);
	}
	return (0);
}

static void	initialize(t_data *d, int argc)
{
	d->size_a = argc - 1;
	d->size_b = 0;
	d->stock_size_a = d->size_a;
	d->rest_div = 0;
	d->rra_i = 0;
	d->ra_i = 0;
	d->rrb_i = 0;
	d->rb_i = 0;
}
