/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 14:51:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	dl_clear(t_double_lst **dl)
{
	t_double_lst	*copydl;
	t_sub_lst		*copysl;

	copydl = *dl;
	while (copydl)
	{
		*dl = copydl->next;
		copysl = copydl->sub_lst;
		while (copysl)
		{
			free(copysl->stack_after_oper);
			copysl = copysl->next;
		}
		free(copydl->sub_lst);
		free(copydl);
		copydl = *dl;
	}
	*dl = NULL;
}
