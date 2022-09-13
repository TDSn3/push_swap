/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tindex_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/10 17:45:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	tindex_clear(t_index **lst)
{
	t_index	*copyl;

	copyl = *lst;
	if (!*lst)
		return ;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl);
		copyl = *lst;
	}
	*lst = NULL;
}
