/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/06 15:50:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list_int.h"

void	tli_clear(t_tli **lst)
{
	t_tli	*copyl;

	copyl = *lst;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl);
		copyl = *lst;
	}
	*lst = NULL;
}
