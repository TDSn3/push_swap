/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 12:35:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_double_lst	*dl_new(void)
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
