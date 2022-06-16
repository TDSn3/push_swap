/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 09:44:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    sa(t_data *d)
{
	int tmp;

	if (!d->stack_a || d->size_a < 2)
		return ;
	else
	{
		tmp = d->stack_a[0];
		d->stack_a[0] = d->stack_a[1];
		d->stack_a[1] = tmp;
	}
	printf("sa\n");
	d->OPER_USED++;
}