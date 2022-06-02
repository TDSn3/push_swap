/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/02 13:55:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int	*dup_stack_a(t_data d);

int main(int argc, char *argv[])
{
	t_data d;

	if (setup_struct(&d, argc, argv))
		return (1);

	sort_five(d);
	show_stack(d, argc);
	free(d.stack_a);
	free(d.stack_b);
	return (0);
}

void	test(t_data *d)
{
	int	i;

	i = 0;
	while (d->size_a > 5)
	{
		pb(&d);
	}
}
