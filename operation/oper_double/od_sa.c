/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   od_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 09:06:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	od_sa(t_data *d)
{
	int	tmp;

	if (!d->stack_a || d->size_a < 2)
		return ;
	else
	{
		tmp = d->stack_a[0];
		d->stack_a[0] = d->stack_a[1];
		d->stack_a[1] = tmp;
	}
}
