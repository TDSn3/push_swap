/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 10:29:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	dl_add_back(t_double_lst **dl, t_double_lst *new_dl)
{
	t_double_lst	*copydl;

	if (dl)
	{
		if (!*dl)
			*dl = new_dl;
		else
		{
			copydl = dl_last(*dl);
			copydl->next = new_dl;
			copydl->next->prev = copydl;
		}
	}
}