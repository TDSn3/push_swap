/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_clear_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:19:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	tli_clear_one(t_tli **tli, int content)
{
	t_tli	*tli_cpy;
	int		tli_size_stock;

	tli_size_stock = tli_size(*tli);
	tli_cpy = *tli;
	if (tli_size_stock == 1)
	{
		free(*tli);
		*tli = NULL;
		return ;
	}	
	while (tli_cpy && tli_cpy->content != content)
		tli_cpy = tli_cpy->next;
	if (tli_cpy->content == content)
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
