/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:00:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/15 19:49:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	find_nb(int index, t_index *index_lst)
{
	t_index	*cpy;

	cpy = index_lst;
	while (cpy)
	{
		if (index == cpy->content_index)
			return (cpy->content_stack);
		else
			cpy = cpy->next;
	}
	return (-1);
}
