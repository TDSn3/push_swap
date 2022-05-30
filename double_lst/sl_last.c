/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:52:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 10:29:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_sub_lst	*sl_last(t_sub_lst *sl)
{
	if (!sl)
		return (NULL);
	while (sl->next)
		sl = sl->next;
	return (sl);
}
