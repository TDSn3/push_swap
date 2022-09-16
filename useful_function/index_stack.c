/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:20:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 18:21:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_index	*index_stack(t_data *d)
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
