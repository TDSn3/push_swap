/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_max_tli.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 08:22:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 06:52:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list_int.h"

t_tli	*find_pos_max_tli(t_tli *tli)
{
	t_tli	*tli_pos;
	t_tli	*tli_cpy;

	tli_cpy = tli->next;
	tli_pos = tli;
	while (tli_cpy)
	{
		if (tli->content < tli_cpy->content)
			tli_pos = tli_cpy;
		tli_cpy = tli_cpy->next;
	}
	return (tli_pos);
}