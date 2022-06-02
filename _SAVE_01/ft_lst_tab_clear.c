/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/19 17:47:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_lst_tab_clear(t_tab **lst)
{
	t_tab	*copyl;

	copyl = *lst;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl->content);
		free(copyl);
		copyl = *lst;
	}
	*lst = NULL;
}
