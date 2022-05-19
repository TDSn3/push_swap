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

int main(int argc, char *argv[])
{
	t_data d;

	d.stack_a = malloc(sizeof(int) * argc - 1);
	if (!d.stack_a)
		return (0);
	d.stack_b = malloc(sizeof(int) * argc - 1);
	if (!d.stack_b)
		return (0);
	d.size_a = argc - 1;
	d.size_b = 0;

	for (int i = 1; i < argc; i++)
	{
		d.stack_a[i - 1] = ft_atoi(argv[i]);
	}


	for (int i = 1; i < argc; i++)
	{
		printf("%d\n", d.stack_a[i - 1]);
	}
	printf("\n- -\na b\n\n");

	ss(d);

	for (int i = 1; i < argc; i++)
	{
		printf("%d\n", d.stack_a[i - 1]);
	}
	printf("\n- -\na b\n\n");

	free(d.stack_a);
	free(d.stack_b);
	return (0);
}