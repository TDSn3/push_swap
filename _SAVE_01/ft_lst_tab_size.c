/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 17:12:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lst_tab_size(t_tab *lst)
{
	t_tab	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	while (nextl)
	{
		nextl = nextl->next;
		i++;
	}
	return (i);
}
