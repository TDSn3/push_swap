/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:26:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	sl_add_back(t_sub_lst **sl, t_sub_lst *new_sl)
{
	t_sub_lst	*copysl;

	if (!new_sl)
		return (1);
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
	return (0);
}
