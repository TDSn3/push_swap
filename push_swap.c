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
void show_stacks(t_data d, int argc);

int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);

//	SHOW FULL STACKS
	for (int i = 1; i < argc; i++)
	{
		printf("%d %d\n", d.stack_a[i - 1], d.stack_b[i- 1]);
	}
	printf("- -\na b\n\n");
//
	if (ascending_order_a(d))
		printf("\nIt is not sorted, in th stack a : %d is bigger than %d", d.stack_a[ascending_order_a(d)], d.stack_a[ascending_order_a(d) + 1]);

	printf("\nBiggest num in stack a is %d, [%d]\n\n", d.stack_a[find_max_a(d)], find_max_a(d));
	show_stacks(d, argc);

	free(d.stack_a);
	free(d.stack_b);

	return (0);
}

void show_stacks(t_data d, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		if (i - 1 < d.size_a)
			printf("%d", d.stack_a[i - 1]);
		else if (i - 1 < d.size_b)
			printf(" ");
		if (i - 1 < d.size_b)
			printf(" %d", d.stack_b[i - 1]);
		if (i - 1 < d.size_a || i - 1 < d.size_b)
			printf("\n");
	}
	printf("- -\na b\n\n");	
}