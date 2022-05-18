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
	int	stack_a[argc - 1];
	int	nb_a;
	int	stack_b[argc - 1];
	int	nb_b;

	nb_a = argc - 1;
	nb_b = 0;

	for (int i = 1; i < argc; i++)
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
	}





	for (int i = 1; i < argc; i++)
	{
		printf("%d\n", stack_a[i - 1]);
	}
	printf("\n- -\na b\n\n");

	sa(stack_a, argc - 1);

	for (int i = 1; i < argc; i++)
	{
		printf("%d\n", stack_a[i - 1]);
	}
	printf("\n- -\na b\n\n");
	return (0);
}