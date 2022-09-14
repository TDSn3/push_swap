/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_min_tindex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 08:22:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/10 17:52:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_index	*find_pos_min_tindex(t_index *tli)
{
	t_index	*tli_pos;
	t_index	*tli_cpy;

	tli_cpy = tli->next;
	tli_pos = tli;
	while (tli_cpy)
	{
		if (tli_pos->content_stack < tli_cpy->content_stack)
			tli_pos = tli_cpy;
		tli_cpy = tli_cpy->next;
	}
	return (tli_pos);
}
