/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_min_tli.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 08:22:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:43:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_tli	*find_pos_min_tli(t_tli *tli)
{
	t_tli	*tli_pos;
	t_tli	*tli_cpy;

	tli_cpy = tli->next;
	tli_pos = tli;
	while (tli_cpy)
	{
		if (tli_pos->content < tli_cpy->content)
			tli_pos = tli_cpy;
		tli_cpy = tli_cpy->next;
	}
	return (tli_pos);
}
