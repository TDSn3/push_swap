/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:01:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int setup_struct(t_data *d, int argc, char **argv)
{
	int	i;

	i = 1;
	d->stack_a = malloc(sizeof(int) * argc - 1);
	if (!d->stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	d->stack_b = malloc(sizeof(int) * argc - 1);
	if (!d->stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	d->size_a = argc - 1;
	d->size_b = 0;
	while (i < argc)
	{
		d->stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}
