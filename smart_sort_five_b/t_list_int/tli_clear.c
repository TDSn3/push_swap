/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 12:51:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../header.h"

void	tli_clear(t_tli **lst)
{
	t_tli	*copyl;

	copyl = *lst;
	if (!*lst)
		return;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl);
		copyl = *lst;
	}
	*lst = NULL;
}
