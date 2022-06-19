/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:43:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	tli_add_back(t_tli **lst, t_tli *new)
{
	t_tli	*copyl;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			copyl = tli_last(*lst);
			copyl->next = new;
			copyl->next->prev = copyl;
		}
	}
}
