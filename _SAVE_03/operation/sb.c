/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:29:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/04 09:44:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    sb(t_data *d)
{
	int tmp;

	if (!d->stack_b || d->size_b < 2)
		return ;
	else
	{
		tmp = d->stack_b[0];
		d->stack_b[0] = d->stack_b[1];
		d->stack_b[1] = tmp;
	}
	printf("sb\n");
	OPER_++;
}