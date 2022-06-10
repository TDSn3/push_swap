/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_setup_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:09:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/08 13:16:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../header.h"

t_tli	*tli_setup_b(t_data *d, t_tli *tli)
{
	int		i;
	int		size;

	if (d->size_a == 0)
		return (NULL);
	if (d->size_a > 5)
		size = 5;
	else
		size = d->size_a;

	i = 0;
	while (i < size)
	{
		tli_add_back(&tli, tli_new(d->stack_a[i]));
		i++;
	}
	return (tli);
}