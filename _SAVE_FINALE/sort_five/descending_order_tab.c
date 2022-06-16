/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descending_order_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:15:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/03 14:21:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int descending_order_tab(int *tab, int size)
{
	int	i;

	i = 0;
	if (!tab || size < 2)
		return (-1);
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			return (i);
		i++;
	}
	return (-1);
}
