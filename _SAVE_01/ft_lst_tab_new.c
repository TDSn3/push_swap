/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tab_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/22 15:45:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tab	*ft_lst_tab_new(int *content, int pos)
{
	t_tab	*ln;

	ln = malloc(sizeof(t_tab));
	if (!ln)
		return (NULL);
	ln->pos = pos;
	ln->content = content;
	ln->next = NULL;
	return (ln);
}
