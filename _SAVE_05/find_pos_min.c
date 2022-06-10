/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 08:22:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/07 13:26:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_pos_min(int *tab, int size)
{
	int	i;
	int	tmp;
	int	tmp_pos;

	i = 1;
	tmp = tab[0];
	tmp_pos = 0;
	while (i < size)
	{
		if (tmp < tab[i])
		{
			tmp = tab[i];
			tmp_pos = i;
		}
		i++;
	}
	return (tmp_pos);
}