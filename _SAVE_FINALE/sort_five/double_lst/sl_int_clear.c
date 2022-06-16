/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_int_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/01 23:46:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	sl_int_clear(t_sub_lst **sl)
{
	t_sub_lst		*copysl;

	copysl = *sl;
	while (copysl)
	{
		*sl = copysl->next;
		free(copysl);
		copysl = *sl;
	}
	*sl = NULL;
}
