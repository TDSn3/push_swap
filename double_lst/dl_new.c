/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/05/30 10:29:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_double_lst	*dl_new()
{
	t_double_lst	*dln;

	dln = malloc(sizeof(t_double_lst));
	if (!dln)
		return (NULL);
	dln->sub_lst = NULL;
	dln->prev = NULL;
	dln->next = NULL;
	return (dln);
}