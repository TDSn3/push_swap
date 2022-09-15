/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tindex_clear_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:50:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	tindex_clear_one(t_index **tli, int content_stack)
{
	t_index	*tli_cpy;
	int		tli_size_stock;

	tli_size_stock = tindex_size(*tli);
	tli_cpy = *tli;
	if (tli_size_stock == 1)
	{
		free(*tli);
		return ;
	}	
	while (tli_cpy && tli_cpy->content_stack != content_stack)
		tli_cpy = tli_cpy->next;
	if (tli_cpy->content_stack == content_stack)
	{
		if (tli_cpy->prev)
			tli_cpy->prev->next = tli_cpy->next;
		if (tli_cpy->next)
		{
			tli_cpy->next->prev = tli_cpy->prev;
			if (tli_cpy == *tli)
				*tli = tli_cpy->next;
		}
		free(tli_cpy);
	}
}
