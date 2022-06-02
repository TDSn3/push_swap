/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab_add_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/22 15:45:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_lst_tab_add_back(t_tab **lst, t_tab *new)
{
	t_tab	*copyl;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			copyl = ft_lst_tab_last(*lst);
			copyl->next = new;
		}
	}
}
