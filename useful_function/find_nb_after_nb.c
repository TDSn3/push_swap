/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nb_after_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:12:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/16 18:13:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	find_nb_after_nb(t_data *d, int nb_stack)
{
	int	i;
	int	j;

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
