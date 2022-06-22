/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:19:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 07:37:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tli	*tli_cpy(t_tli *tli, t_tli *stock_tli_a_ten)
{
	t_tli	*tli_i;

	tli_i = tli;
	while (tli_i)
	{
		tli_add_back(&stock_tli_a_ten, tli_new(tli_i->content));
		tli_i = tli_i->next;
	}
	return (stock_tli_a_ten);
}
