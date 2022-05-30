/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:18:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 13:18:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    sl_link(t_sub_lst *sl, t_sub_lst *sl_prev)
{
	if (!sl)
		return ;
	sl->prev_oper = sl_prev;
	sl_prev->next_oper = sl;
}