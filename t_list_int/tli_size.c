/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tli_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 07:50:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list_int.h"

int	tli_size(t_tli *lst)
{
	t_tli	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		nextl = nextl->next;
		i++;
	}
	return (i);
}
