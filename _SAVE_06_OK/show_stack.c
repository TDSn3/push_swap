/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:29:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/08 20:28:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_stack(t_data d, int argc)
{
	int	i;
	
	i = 1;
	printf("\033[36;01m");
	while (i < argc)
	{
		if (i - 1 < d.size_a)
			printf("%d", d.stack_a[i - 1]);
		else if (i - 1 < d.size_b)
			printf(" ");
		if (i - 1 < d.size_b)
			printf("\t%d", d.stack_b[i - 1]);
		if (i - 1 < d.size_a || i - 1 < d.size_b)
			printf("\n");
		i++;
	}
	printf("\n\033[00m");
	printf("\033[35m");
	printf("---------\na\tb");
	printf("\n\033[00m");	
}
