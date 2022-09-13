/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/13 12:19:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	setup_struct(t_data *d, int argc, char **argv)
{
	int	i;

	i = 1;

	d->stack_a = malloc(sizeof(int) * argc - 1);
	if (!d->stack_a)
		return (return_error());
	d->stack_b = malloc(sizeof(int) * argc - 1);
	if (!d->stack_b)
		return (return_error());

	d->cpy_stack_a = malloc(sizeof(int) * argc - 1);
	if (!d->cpy_stack_a)
		return (return_error());
	d->cpy_stack_b = malloc(sizeof(int) * argc - 1);
	if (!d->cpy_stack_b)
		return (return_error());

	d->size_a = argc - 1;
	d->size_b = 0;
	d->stock_size_a = d->size_a;
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
		return (return_error());
	}
	return (0);
}
