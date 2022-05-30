/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 10:29:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sl_add_back(t_sub_lst **sl, t_sub_lst *new_sl)
{
	t_sub_lst	*copysl;

	if (sl)
	{
		if (!*sl)
			*sl = new_sl;
		else
		{
			copysl = sl_last(*sl);
			copysl->next = new_sl;
			copysl->next->prev = copysl;
		}
	}
}
